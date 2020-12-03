`include "define.vh"
`include "fetch.v"
`include "decoder.v"
`include "data_mem.v"
`include "execute.v"
`include "write_back.v"
`include "reg_file.v"


module cpu(
    input wire clk,
    input wire rst,
    output wire uart
    );
	
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

    wire [31:0] r_addr;
    wire [31:0] w_data;
    wire [31:0] r_data;


	

	fetch fetch_body
		(.pc(pc)

		,.ir(ir));

	decoder decoder_body(
        .ir(ir),
        .clk(clk),

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

	data_mem data_mem_body(
		.clk(sysclk),
		.alucode(alucode),
		.is_store(is_store), //decoderより。load,storeするかどうか
        .is_load(is_load),
        .addr(alu_result),
        .w_data(srcreg2_data),

        .r_data(r_data)//resultに格納してrdに
	);

	writeback writeback_body
		(.clk(clk)
		,.rst(rst)
		,.nextpc(nextpc)
		,.pc(pc));


	assign dstreg_data =  is_load   ? r_data
									: alu_result;

	register_file register_file_body(
        .rst(rst),
        .reg_we(reg_we),       // レジスタ書き込みの有無
        .srcreg1_num(srcreg1_num),//assignなのでつねに帰ってくる
        .srcreg2_num(srcreg2_num),
        .dstreg_num(dstreg_num),
        .dstreg_data(dstreg_data),

        .srcreg1_data(srcreg1_data),
        .srcreg2_data(srcreg2_data)
    );

  initial begin
    $display("pc=%d, pc=%b, reg1=%d, reg2=%d, uart=%d\n", pc, ir, srcreg1_data, srcreg2_data, uart);
  end

endmodule
