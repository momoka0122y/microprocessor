
`timescale 1ns / 1ps

`include "define.vh"

//必要な、レジスタに記されている値を取り出したり、書き込んだりする
module register_file(
    input wire clk,
    input wire rst,
    input wire	     	reg_we,       // レジスタ書き込みの有無
    input wire [4:0] srcreg1_num,
    input wire [4:0] srcreg2_num,
    
    input wire [4:0] dstreg_num,
    input wire [31:0] dstreg_data,

    output wire [31:0] srcreg1_data,
    output wire [31:0] srcreg2_data
);
    reg [31:0] register_file [0:31];

    assign srcreg1_data=register_file[srcreg1_num];
    assign srcreg2_data=register_file[srcreg2_num];
    
    integer i;
    initial begin
        register_file[5'd0]=32'd0; //ゼロレジスタ
    end

    
    always @(posedge clk or negedge rst) begin
        if (rst == 1'b0) begin //reset
            `ifdef DEBUG
                $display("reset!");
            `endif
            for (i=0;i<32;i=i+1) begin
                register_file[i] <= 32'h00000000;
            end
        end
        else begin
            if(reg_we==`ENABLE && dstreg_num != 5'd0) begin //書き込み
                `ifdef DEBUG
                     $strobe("register_file:\tregister_file[%d] <= %h", dstreg_num, dstreg_data);
                `endif
                register_file[dstreg_num] <= dstreg_data;
            end
        end
    end
    `ifdef DEBUG
        always @(posedge clk) begin
            for (i=0;i<32;i=i+1) begin
                $display("%d:%h",i,register_file[i]);
            end
        end
    `endif
endmodule
