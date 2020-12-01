`timescale 1ns / 1ps

`include "define.vh"

module alu(
    input wire [5:0] alucode,       // 演算種別
    input wire [31:0] op1,          // 入力データ1
    input wire [31:0] op2,          // 入力データ2

    output reg [31:0] alu_result,   // 演算結果
    output reg br_taken             // 分岐の有無
    );

  always @(*) begin
    case (alucode)
      `ALU_LUI  : begin
                  alu_result <= {op2[31:12],12'b0};
                  br_taken <= `DISABLE;
                  end

      `ALU_JAL  : begin
                  alu_result <= op2 + 'd4;
                  br_taken <= `ENABLE;
                  end

      `ALU_JALR : begin
                  alu_result <= op2 + 'd4;
                  br_taken <= `ENABLE;
                  end

      `ALU_BEQ  : begin
                  if (op1 == op2) br_taken <= `ENABLE;
                  else br_taken <= `DISABLE;
                  alu_result <= 0;
                  end

      `ALU_BNE  : begin
                  if (op1 != op2) br_taken <= `ENABLE;
                  else br_taken <= `DISABLE;
                  alu_result <= 0;
                  end

      `ALU_BLT  : begin
                  if ($signed(op1) < $signed(op2)) br_taken <= `ENABLE;
                  else br_taken <= `DISABLE;
                  alu_result <= 0;
                  end

      `ALU_BGE  : begin
                  if ($signed(op1) < $signed(op2)) br_taken <= `DISABLE;
                  else br_taken <= `ENABLE;
                  alu_result <= 0;
                  end

      `ALU_BLTU : begin
                  if (op1 < op2) br_taken <= `ENABLE;
                  else br_taken <= `DISABLE;
                  alu_result <= 0;
                  end

      `ALU_BGEU : begin
                  if (op1 < op2) br_taken <= `DISABLE;
                  else br_taken <= `ENABLE;
                  alu_result <= 0;
                  end

      `ALU_LB   : begin
                  alu_result <= op1 + op2;
                  br_taken <= `DISABLE;
                  end
                  
      `ALU_LH   : begin
                  alu_result <= op1 + op2;
                  br_taken <= `DISABLE;
                  end

      `ALU_LW   : begin
                  alu_result <= op1 + op2;
                  br_taken <= `DISABLE;
                  end

      `ALU_LBU  : begin
                  alu_result <= op1 + op2;
                  br_taken <= `DISABLE;
                  end

      `ALU_LHU  : begin
                  alu_result <= op1 + op2;
                  br_taken <= `DISABLE;
                  end

      `ALU_SB   : begin
                  alu_result <= op1 + op2;
                  br_taken <= `DISABLE;
                  end

      `ALU_SH   : begin
                  alu_result <= op1 + op2;
                  br_taken <= `DISABLE;
                  end

      `ALU_SW   : begin
                  alu_result <= op1 + op2;
                  br_taken <= `DISABLE;
                  end

      `ALU_ADD  : begin
                  alu_result <= op1 + op2;
                  br_taken <= `DISABLE;
                  end

      `ALU_SUB  : begin
                  alu_result <= op1 - op2;
                  br_taken <= `DISABLE;
                  end

      `ALU_SLT  : begin
                  if ($signed(op1) < $signed(op2)) alu_result <= `ENABLE;
                  else alu_result <= `DISABLE;
                  br_taken <= 0;
                  end

      `ALU_SLTU : begin
                  if ($unsigned(op1) < $unsigned(op2)) alu_result <= `ENABLE;
                  else alu_result <= `DISABLE;
                  br_taken <= 0;
                  end

      `ALU_XOR  : begin
                  alu_result <= op1 ^ op2;
                  br_taken <= `DISABLE;
                  end

      `ALU_OR   : begin
                  alu_result <= op1 | op2;
                  br_taken <= `DISABLE;
                  end

      `ALU_AND  : begin
                  alu_result <= op1 & op2;
                  br_taken <= `DISABLE;
                  end

      `ALU_SLL  : begin
                  alu_result <= op1 << op2[4:0];
                  br_taken <= `DISABLE;
                  end

      `ALU_SRL  : begin
                  alu_result <= op1 >> op2[4:0];
                  br_taken <= `DISABLE;
                  end

      `ALU_SRA  : begin
                  alu_result <= $signed(op1) >>> op2[4:0];
                  br_taken <= `DISABLE;
                  end
    endcase
  end
endmodule
