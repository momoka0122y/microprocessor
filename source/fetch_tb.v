`include "fetch.v"
`include "decoder.v"


`define assertf(name, signal, value) \
        if (signal !== value) begin \
            $display("ASSERTION FAILED in %s : signal is '0x%x' but expected '0x%x'!", name, signal, value); \
            $finish; \
        end else begin \
            $display("    signal == value"); \
        end

`define test_fetch(name, ex_ir) \
        $display("%s:", name); \
        `assertf("result", ir, ex_ir) \
        $display("%s test passed\n", name); \

`define assert(name, signal, value) \
        if (signal !== value) begin \
            $display("ASSERTION FAILED in %s : signal is '%d' but expected '%d'", name, signal, value); \
            $finish; \
        end else begin \
            $display("\t%m: signal == value"); \
        end

`define test_decode(name, ir,ex_ir, ex_srcreg1_num, ex_srcreg2_num, ex_dstreg_num, ex_imm, ex_alucode, ex_aluop1_type, ex_aluop2_type, ex_reg_we, ex_is_load, ex_is_store, ex_is_halt) \
        $display("%s:", name); \
        $display("\tcodeword: %b", ir,); \
        `assert("ir", ir, ex_ir) \
        `assert("srcreg1_num", srcreg1_num, ex_srcreg1_num) \
        `assert("srcreg2_num", srcreg2_num, ex_srcreg2_num) \
        `assert("dstreg_num", dstreg_num, ex_dstreg_num) \
        `assert("imm", imm, ex_imm) \
        `assert("alucode", alucode, ex_alucode) \
        `assert("aluop1_type", aluop1_type, ex_aluop1_type) \
        `assert("aluop2_type", aluop2_type, ex_aluop2_type) \
        `assert("reg_we", reg_we, ex_reg_we) \
        `assert("is_load", is_load, ex_is_load) \
        `assert("is_store", is_store, ex_is_store) \
        $display("%s test ...ok\n", name); \

module fetch_tb;
    reg [31:0] pc;
    wire [31:0] ir;

    wire clk;

    wire  [4:0]	srcreg1_num;  // reg1   ソースレジスタ1番号
    wire  [4:0]	srcreg2_num;  // reg2   ソースレジスタ2番号
    wire  [4:0]	dstreg_num;   // rd     デスティネーションレジスタ番号
    wire [31:0]	imm;          // imm[:] 即値

    wire   [5:0]	alucode;     // ALUの演算種別
    wire   [1:0]	aluop1_type;  // ALUの入力タイプ
    wire   [1:0]	aluop2_type;  // ALUの入力タイプ

    wire	     	reg_we;      // レジスタ書き込みの有無
    wire		    is_load;      // ロード命令判定フラグ
    wire		    is_store;     // ストア命令判定フラグ
    wire          is_halt;

    fetch fetch(
        .pc(pc)
        ,.ir(ir));

    decoder decoder(
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
        .is_halt(is_halt)
    );
    initial begin
    //   pc = 8192;
    //   pc = 8194;
      pc = 32'h8000;
    //   pc = 32'h0000;
      $display("%d",pc);
      $display("%d",pc[31:2]);
      #10

        `test_fetch("fetch", 32'h0080006f)
        `test_decode("JAL", ir, 00000000110000000000000001101111,0, 0, 0, 12, `ALU_JAL, `OP_TYPE_NONE, `OP_TYPE_PC, `DISABLE, `DISABLE, `DISABLE, `DISABLE)

        $display("all tests passed!");
    end

endmodule