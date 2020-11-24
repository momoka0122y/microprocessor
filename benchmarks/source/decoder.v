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


always @(posedge clk) begin

    case(ir[6:0]) // 9 cases
    `OPIMM:begin
    end

    `OP:begin
    end

    `LUI:begin
    end

    `AUIPC:begin
    end