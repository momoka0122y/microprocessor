`timescale 1ns / 1ps

`include "define.vh"

module decoder(
    input  wire [31:0]  ir,           // 機械語命令列
    input wire clk,

    output wire  [4:0]	srcreg1_num,  // reg1   ソースレジスタ1番号
    output wire  [4:0]	srcreg2_num,  // reg2   ソースレジスタ2番号
    output wire  [4:0]	dstreg_num,   // rd     デスティネーションレジスタ番号
    output wire [31:0]	imm,          // imm[:] 即値

    output reg   [5:0]	alucode,      // ALUの演算種別
    output reg   [1:0]	aluop1_type,  // ALUの入力タイプ
    output reg   [1:0]	aluop2_type,  // ALUの入力タイプ

    output reg	     	reg_we,       // レジスタ書き込みの有無
    output reg		    is_load,      // ロード命令判定フラグ
    output reg		    is_store,     // ストア命令判定フラグ
    output reg          is_halt
);



always @(ir) begin

    case(ir[6:0]) // opcode  //9 cases
    `OPIMM:begin  // imm, rs1, type, rd, case
        test(name, ir, ex_srcreg1_num, ex_srcreg2_num, ex_dstreg_num, ex_imm, ex_alucode, ex_aluop1_type, ex_aluop2_type, ex_reg_we, ex_is_load, ex_is_store, ex_is_halt)
        ir = 32'hfff00513; #10;
        `test("ADDI", ir, 0, 0, 10, 32'hffffffff, `ALU_ADD, `OP_TYPE_REG, `OP_TYPE_IMM, `ENABLE, `DISABLE, `DISABLE, `DISABLE)
        
        ir = 32'h5a613; #10;
        `test("SLTI", ir, 11, 0, 12, 0, `ALU_SLT, `OP_TYPE_REG, `OP_TYPE_IMM, `ENABLE, `DISABLE, `DISABLE, `DISABLE)

        ir = 32'h279793; #10;
        , , , )

        // srcreg1_num
        srcreg1_num <= ir[19:15];

        // srcreg2_num
        srcreg2_num <= 5'b00000;

        // dstreg_num
        dstreg_num <= ir[11:7];

        // imm
        if(ir[13:12]===2'b01) imm <= {{28{ir[24]}},ir[23:20]};
        else                  imm <= {{20{ir[31]}},ir[31:20]};

        // alucode
        case(ir[14:12])
            `OP_ADDi : alucode<=`ALU_ADD;
            `OP_SLTi : alucode<=`ALU_SLT;
            `OP_SLTiu : alucode<=`ALU_SLTU;
            `OP_XORi : alucode <= `ALU_XOR;
            `OP_ORi : alucode <= `ALU_OR;
            `OP_ANDi :alucode <= `ALU_AND;
            `OP_SLLi :alucode <= `ALU_SLL;
            `OP_SRi :alucode <= ir[30]?`ALU_SRA:`ALU_SRL;
            default:alucode <=`UNUSED;
        endcase
        // aluop1_type
        aluop1_type <= `OP_TYPE_REG

        // aluop2_type
        aluop2_type <= `OP_TYPE_IMM

        // reg_we
        reg_we <= `ENABLE
        
        // is_load
        is_load <= `DISABLE

        // is_store
        is_store <= `DISABLE

        // is_halt
        is_halt <= `DISABLE

    end

    `OP:begin
    end

    `LUI:begin
    end

    `AUIPC:begin
    end

    `JAL:begin
    end

    `JALR:begin
    end

    `BRANCH:begin
    end

    `STORE:begin
    end

    `LOAD:begin
    end