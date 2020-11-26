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

reg [2:0] op_type;


  assign srcreg1_num = (op_type == `TYPE_U) ? 5'b0:
                       (op_type == `TYPE_J) ? 5'b0:
                       (op_type == `TYPE_I) ? ir[19:15]:
                       (op_type == `TYPE_B) ? ir[19:15]:
                       (op_type == `TYPE_S) ? ir[19:15]:
                       (op_type == `TYPE_R) ? ir[19:15]:
                       5'b0;                       

  assign srcreg2_num = (op_type == `TYPE_U) ? 0:
                       (op_type == `TYPE_J) ? 0:
                       (op_type == `TYPE_I) ? 0:
                       (op_type == `TYPE_B) ? ir[24:20]:
                       (op_type == `TYPE_S) ? ir[24:20]:
                       (op_type == `TYPE_R) ? ir[24:20]:
                       5'b0;

  assign dstreg_num =  (op_type == `TYPE_U) ? ir[11:7]:
                       (op_type == `TYPE_J) ? ir[11:7]:
                       (op_type == `TYPE_I) ? ir[11:7]:
                       (op_type == `TYPE_B) ? 0:
                       (op_type == `TYPE_S) ? 0:
                       (op_type == `TYPE_R) ? ir[11:7]:
                       5'b0;
                       
  assign imm = 
              (op_type == `TYPE_U) ? {ir[31:12],12'b0}:
              (op_type == `TYPE_J) ? {{11{ir[31]}},ir[31],ir[19:12],ir[20],ir[30:21], 1'b0}:
              ((op_type == `TYPE_I) && (ir[13:12] == 2'b01)) 
                                   ? {{27{ir[24]}},ir[24:20]}:
              (op_type == `TYPE_I) ? {{20{ir[31]}},ir[31:20]}:
              (op_type == `TYPE_B) ? {{19{ir[31]}},ir[31],ir[7],ir[30:25],ir[11:8],1'b0}:
              (op_type == `TYPE_S) ? {{20{ir[31]}},ir[31:25],ir[11:7]}:
              (op_type == `TYPE_R) ? 32'b0:
              32'b0;
  


always @(ir) begin

    case(ir[6:0]) // opcode  //9 cases
    `OPIMM:begin

        // // srcreg1_num, srcreg2_num, dstreg_num, imm
        op_type <= `TYPE_I;
        
        // alucode
        case(ir[14:12])
            3'b000 : alucode <= `ALU_ADD;
            3'b010 : alucode <= `ALU_SLT;
            3'b011 : alucode <= `ALU_SLTU;
            3'b100 : alucode <= `ALU_XOR;
            3'b110 : alucode <= `ALU_OR;
            3'b111 :alucode <= `ALU_AND;
            3'b001 :alucode <= `ALU_SLL;
            3'b101 :alucode <= ir[30] ? `ALU_SRA : `ALU_SRL;
        endcase

        aluop1_type <= `OP_TYPE_REG;
        aluop2_type <= `OP_TYPE_IMM;
        reg_we <= `ENABLE;
        is_load <= `DISABLE;
        is_store <= `DISABLE;
        is_halt <= `DISABLE;

    end

    `OP:begin
            // // srcreg1_num, srcreg2_num, dstreg_num, imm
        op_type <= `TYPE_R;
        
        // alucode
        case(ir[14:12])
            3'b000 : alucode <= ir[30] ?  `ALU_SUB : `ALU_ADD;
            3'b010 : alucode <= `ALU_SLT;
            3'b011 : alucode <= `ALU_SLTU;
            3'b100 : alucode <= `ALU_XOR;
            3'b110 : alucode <= `ALU_OR;
            3'b111 :alucode <= `ALU_AND;
            3'b001 :alucode <= `ALU_SLL;
            3'b101 :alucode <= ir[30] ? `ALU_SRA : `ALU_SRL;
        endcase
        
        aluop1_type <= `OP_TYPE_REG;
        aluop2_type <= `OP_TYPE_REG;
        reg_we <= `ENABLE;
        is_load <= `DISABLE;
        is_store <= `DISABLE;
        is_halt <= `DISABLE;
    end

    `LUI:begin
        op_type <= `TYPE_U;
        alucode <= `ALU_LUI;
        reg_we <= `ENABLE;
        aluop1_type <= `OP_TYPE_NONE;
        aluop2_type <= `OP_TYPE_IMM;
        is_load <= `DISABLE;
        is_store <= `DISABLE;
        is_halt <= `DISABLE;
    end

    `AUIPC : begin
        op_type <= `TYPE_U;
        reg_we <= `ENABLE;
        alucode <= `ALU_ADD;
        aluop1_type <= `OP_TYPE_IMM;
        aluop2_type <= `OP_TYPE_PC;
        is_load <= `DISABLE;
        is_store <= `DISABLE;
        is_halt <= `DISABLE;
      end

      `JAL   : begin
        op_type <= `TYPE_J;
        // $display(ir[11:7] == 5'b00000);
        // $display(ir[11:7]);
        // if (ir[11:7] == 5'b00000) reg_we <= `DISABLE;
        // else reg_we <= `ENABLE;
        reg_we <= ir[11:7] ?  `ENABLE : `DISABLE;
        
        alucode <= `ALU_JAL;
        aluop1_type <= `OP_TYPE_NONE;
        aluop2_type <= `OP_TYPE_PC;
        is_load <= `DISABLE;
        is_store <= `DISABLE;
        is_halt <= `DISABLE;
      end

      `JALR  : begin
        op_type <= `TYPE_I;
        reg_we <= ir[11:7] ?  `ENABLE : `DISABLE;
        alucode <= `ALU_JALR;
        aluop1_type <= `OP_TYPE_REG;
        aluop2_type <= `OP_TYPE_PC;
        is_load <= `DISABLE;
        is_store <= `DISABLE;
        is_halt <= `DISABLE;
      end

    `BRANCH: begin
        op_type <= `TYPE_B;
        reg_we <= `DISABLE;
        aluop1_type <= `OP_TYPE_REG;
        aluop2_type <= `OP_TYPE_REG;
        is_load <= `DISABLE;
        is_store <= `DISABLE;
        is_halt <= `DISABLE;

        case(ir[14:12])
          3'd0: alucode <= `ALU_BEQ;
          3'd1: alucode <= `ALU_BNE;
          3'd4: alucode <= `ALU_BLT;
          3'd5: alucode <= `ALU_BGE;
          3'd6: alucode <= `ALU_BLTU;
          3'd7: alucode <= `ALU_BGEU;
        endcase
      end

    `STORE : begin
        op_type <= `TYPE_S;
        reg_we <= `DISABLE;
        aluop1_type <= `OP_TYPE_REG;
        aluop2_type <= `OP_TYPE_IMM;
        is_load <= `DISABLE;
        is_store <= `ENABLE;
        is_halt <= `DISABLE;

        case(ir[14:12])
          3'd0: alucode <= `ALU_SB;
          3'd1: alucode <= `ALU_SH;
          3'd2: alucode <= `ALU_SW;
        endcase
      end

    `LOAD  : begin
        op_type <= `TYPE_I;
        reg_we <= `ENABLE;
        aluop1_type <= `OP_TYPE_REG;
        aluop2_type <= `OP_TYPE_IMM;
        is_load <= `ENABLE;
        is_store <= `DISABLE;
        is_halt <= `DISABLE;

        case(ir[14:12])
          3'd0: alucode <= `ALU_LB;
          3'd1: alucode <= `ALU_LH;
          3'd2: alucode <= `ALU_LW;
          3'd4: alucode <= `ALU_LBU;
          3'd5: alucode <= `ALU_LHU;
        endcase
      end
    endcase
end
endmodule