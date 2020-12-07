`include "cpu.v"

module cpu_tb;
    reg sysclk;
    reg cpu_resetn;
    wire uart_tx;

    parameter CYCLE = 100;

    always #(CYCLE/2) sysclk = ~sysclk;

    cpu cpu(
       .sysclk(sysclk),
       .cpu_resetn(cpu_resetn),
       .uart_tx(uart_tx)
    );


    initial begin
        #10     sysclk     = 1'd0;
                cpu_resetn    = 1'd0;
        #(CYCLE) cpu_resetn = 1'd1; 
        #(3276800* CYCLE) $finish; //実行サイクル数以上を指定する
        
    end


endmodule

