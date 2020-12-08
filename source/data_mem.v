`timescale 1ns / 1ps

`include "define.vh"

//alucodeがload.storeのときにData memoryからロードとかストアする
module data_mem(
    input wire clk,
    input wire [5:0] alucode,
    input wire is_store, //decoderより。load,storeするかどうか
    input wire is_load,  //正直これはcpu.vで使ってるからここではいらない
    input wire [31:0] addr,
    input wire [31:0] w_data,
    output wire [31:0] r_data
);
    //RAM
    reg [31:0] ram [0:32767];

    initial $readmemh("/home/denjo/microprocessor/benchmarks/Coremark_for_Synthesis/data.hex", ram);
    // initial $readmemh("/Users/momoka/git/microprocessor/benchmarks/Coremark/data.hex", ram);



    assign r_data = (alucode == `ALU_LB  &&  addr[1:0] == 2'd0) ? {{24{ram[addr[16:2]][7]}}, ram[addr[16:2]][7:0]}:
                    (alucode == `ALU_LB  &&  addr[1:0] == 2'd1) ? {{24{ram[addr[16:2]][15]}}, ram[addr[16:2]][15:8]}:
                    (alucode == `ALU_LB  &&  addr[1:0] == 2'd2) ? {{24{ram[addr[16:2]][23]}}, ram[addr[16:2]][23:16]}:
                    (alucode == `ALU_LB  &&  addr[1:0] == 2'd3) ? {{24{ram[addr[16:2]][31]}}, ram[addr[16:2]][31:24]}:

                    (alucode == `ALU_LH  &&  addr[1:0] == 2'd0) ? {{16{ram[addr[16:2]][15]}}, ram[addr[16:2]][15:0]}:
                    (alucode == `ALU_LH  &&  addr[1:0] == 2'd1) ? {{16{ram[addr[16:2]][23]}}, ram[addr[16:2]][23:8]}:
                    (alucode == `ALU_LH  &&  addr[1:0] == 2'd2) ? {{16{ram[addr[16:2]][31]}}, ram[addr[16:2]][31:16]}:

                    (alucode == `ALU_LW  &&  addr[1:0] == 2'd3) ? ram[addr[16:2]][31:0]:

                    (alucode == `ALU_LBU  &&  addr[1:0] == 2'd0) ? {{24{1'b0}}, ram[addr[16:2]][7:0]}:
                    (alucode == `ALU_LBU  &&  addr[1:0] == 2'd1) ? {{24{1'b0}}, ram[addr[16:2]][15:8]}:
                    (alucode == `ALU_LBU  &&  addr[1:0] == 2'd2) ? {{24{1'b0}}, ram[addr[16:2]][23:16]}:
                    (alucode == `ALU_LBU  &&  addr[1:0] == 2'd3) ? {{24{1'b0}}, ram[addr[16:2]][31:24]}:

                    (alucode == `ALU_LHU  &&  addr[1:0] == 2'd0) ? {{16{1'b0}}, ram[addr[16:2]][15:0]}:
                    (alucode == `ALU_LHU  &&  addr[1:0] == 2'd1) ? {{16{1'b0}}, ram[addr[16:2]][23:8]}:
                    (alucode == `ALU_LHU  &&  addr[1:0] == 2'd2) ? {{16{1'b0}}, ram[addr[16:2]][31:16]}:

                    ram[addr[16:2]][31:0]; //どれにも当てはまらなかったら困る。とりあえず`ALU_LWと同じにする。



    always @(posedge clk) begin
        if(is_store) begin//store命令
            case(alucode)
                `ALU_SB : begin //ram[num]にwrite_dataの下8bitをストアする
                    case(addr[1:0])
                        2'd0: ram[addr[16:2]][7:0] <= w_data[7:0];
                        2'd1: ram[addr[16:2]][15:8] <= w_data[7:0];
                        2'd2: ram[addr[16:2]][23:16] <= w_data[7:0];
                        2'd3: ram[addr[16:2]][31:24] <= w_data[7:0];
                    endcase
                end
                `ALU_SH : begin
                    case(addr[1:0])
                        2'd0: ram[addr[16:2]][15:0] <= w_data[15:0];
                        2'd1: ram[addr[16:2]][23:8] <= w_data[15:0];
                        2'd2: ram[addr[16:2]][31:16] <= w_data[15:0];
                        2'd3:;
                    endcase
                end
                `ALU_SW : begin    
                    ram[addr[16:2]]<= w_data[31:0];
                end
            endcase
        end
        // if(is_load) begin
        //     case(alucode)
        //         `ALU_LB : begin
        //             case(addr[1:0])
        //                 2'd0: r_data <= {{24{ram[addr[16:2]][7]}}, ram[addr[16:2]][7:0]};
        //                 2'd1: r_data <= {{24{ram[addr[16:2]][15]}}, ram[addr[16:2]][15:8]};
        //                 2'd2: r_data <= {{24{ram[addr[16:2]][23]}}, ram[addr[16:2]][23:16]};
        //                 2'd3: r_data <= {{24{ram[addr[16:2]][31]}}, ram[addr[16:2]][31:24]};
        //             endcase    
        //         end
        //         `ALU_LH : begin
        //             case(addr[1:0])
        //                 2'd0: r_data <= {{24{ram[addr[16:2]][15]}}, ram[addr[16:2]][15:0]};
        //                 2'd1: r_data <= {{24{ram[addr[16:2]][23]}}, ram[addr[16:2]][23:8]};
        //                 2'd2: r_data <= {{24{ram[addr[16:2]][31]}}, ram[addr[16:2]][31:16]};
        //                 2'd3: ;
        //             endcase
        //         end
        //         `ALU_LW : begin
        //             r_data <= ram[addr[16:2]][31:0];
        //         end
        //         `ALU_LBU : begin
        //             case(addr[1:0])
        //                 2'd0: r_data <= {{24{1'b0}}, ram[addr[16:2]][7:0]};
        //                 2'd1: r_data <= {{24{1'b0}}, ram[addr[16:2]][15:8]};
        //                 2'd2: r_data <= {{24{1'b0}}, ram[addr[16:2]][23:16]};
        //                 2'd3: r_data <= {{24{1'b0}}, ram[addr[16:2]][31:24]};
        //             endcase
        //         end
        //         `ALU_LHU : begin
        //             case(addr[1:0])
        //                 2'd0: r_data <= {{24{1'b0}}, ram[addr[16:2]][15:0]};
        //                 2'd1: r_data <= {{24{1'b0}}, ram[addr[16:2]][23:8]};
        //                 2'd2: r_data <= {{24{1'b0}}, ram[addr[16:2]][31:16]};
        //                 2'd3: ;
        //             endcase
        //         end
        //     endcase
        // end
    end
endmodule
