`timescale 1ns / 1ps


module cpu(
    input wire sysclk,
    input wire cpu_resetn,
    output wire uart_tx
    );
    wire rst;
    assign rst = cpu_resetn;
	
	wire [31:0] pc; //プログラムカウンタ
    wire [31:0] ir; //

    wire [4:0]  srcreg1_num;     
    wire [4:0]  srcreg2_num;     
    wire [4:0]  dstreg_num;    
    wire [31:0] imm;
    wire [5:0]	alucode;    
    wire [1:0]	aluop1_type; 
    wire [1:0]	aluop2_type;  
    wire	    reg_we;       
    wire	    is_load;     
    wire		is_store;    
    wire        is_halt;

    wire [31:0] srcreg1_data;
    wire [31:0] srcreg2_data;
    wire [31:0] nextpc;
    wire [31:0] alu_result;

    wire [31:0] dstreg_data;

	wire [31:0] ram_addr;

//    wire [31:0] r_addr;
   wire [31:0] w_data;
    wire [31:0] r_data;

	wire [31:0] hc_OUT_data;

	// uart
	wire [7:0] uart_IN_data;
    wire uart_we;
    wire uart_OUT_data;
	

	fetch fetch_body
		(.pc(pc)

		,.ir(ir));

	decoder decoder_body(
        .ir(ir),
        .clk(sysclk),

        .srcreg1_num(srcreg1_num),
        .srcreg2_num(srcreg2_num),
        .dstreg_num(dstreg_num),
        .imm(imm),
        .alucode(alucode),
        .aluop1_type(aluop1_type),
        .aluop2_type(aluop2_type),
        .reg_we(reg_we),
        .is_load(is_load),
        .is_store(is_store),
        .is_halt(is_halt) //分岐命令の時に使う
    );
	

	execute execute_body(
		.pc(pc),
		.aluop1_type(aluop1_type),
		.aluop2_type(aluop2_type),
		.alucode(alucode),
		.srcreg1(srcreg1_data),
		.srcreg2(srcreg2_data),
		.imm(imm),

		.alu_result(alu_result),
		.npc(nextpc)
	);

	assign ram_addr = alu_result;

	data_mem data_mem_body(
		.clk(sysclk),
		.alucode(alucode),
		.is_store(is_store), //decoderより。load,storeするかどうか
        .is_load(is_load),
        .addr(ram_addr),
        .w_data(w_data),

        .r_data(r_data)//resultに格納してrdに
	);

	writeback writeback_body
		(.clk(sysclk)
		,.rst(rst)
		,.nextpc(nextpc)
		,.pc(pc));

	// ハードウェアカウンタ用アドレス（32'hffffff00）を指定して LW 命令をおこなった際に、データメモリの値ではなく、ハードウェアカウンタの値を読みだす.
	assign dstreg_data =  is_load   ? ( ((alucode == `ALU_LW) && (ram_addr == `HARDWARE_COUNTER_ADDR))  ? hc_OUT_data : r_data )
									: alu_result;

	assign uart_IN_data = w_data[7:0];  // ストアするデータをモジュールへ入力
    assign uart_we = ((ram_addr == `UART_ADDR) && (is_store == `ENABLE)) ? 1'b1 : 1'b0;  // シリアル通信用アドレスへのストア命令実行時に送信開始信号をアサート
    assign uart_tx = uart_OUT_data;  // シリアル通信モジュールの出力はFPGA外部へと出力

	register_file register_file_body(
        .clk(sysclk),
        .rst(rst),
        .reg_we(reg_we),       // レジスタ書き込みの有無
        .srcreg1_num(srcreg1_num),//assignなのでつねに帰ってくる
        .srcreg2_num(srcreg2_num),
        .dstreg_num(dstreg_num),
        .dstreg_data(dstreg_data),

        .srcreg1_data(srcreg1_data),
        .srcreg2_data(srcreg2_data)
    );

	assign w_data = srcreg2_data;

    hardware_counter hardware_counter0(
        .CLK_IP(sysclk),
        .RSTN_IP(rst),
        .COUNTER_OP(hc_OUT_data)
    );



    uart uart0(
        .uart_wr_i(uart_we),
        .uart_dat_i(uart_IN_data),
        .sys_clk_i(sysclk),
        .sys_rstn_i(rst),

		.uart_tx(uart_OUT_data)
    );

  initial begin
    $display("pc=%d, ir=%b, reg1=%d, reg2=%d, uart=%d\n", pc, ir, srcreg1_data, srcreg2_data, uart_tx);
  end

endmodule
