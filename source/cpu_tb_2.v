`include "cpu.v"

module cpu_tb_2;
    reg sysclk;
    reg cpu_resetn;
    wire uart_tx;

    parameter CYCLE = 100;

    always #(CYCLE/2) sysclk = ~sysclk;

    cpu cpu(
       .clk(sysclk),
       .rst(cpu_resetn),
       .uart(uart_tx)
    );


    initial begin
        #10     sysclk     = 1'd0;
                cpu_resetn    = 1'd0;
        #(CYCLE) cpu_resetn = 1'd1; 
        #(3276800* CYCLE) $finish; //実行サイクル数以上を指定する
        
    end


endmodule

