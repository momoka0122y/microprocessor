`include "define.vh"
`include "alu.v"

module execute(
    input wire [31:0] pc,
    input wire [1:0] aluop1_type,
    input wire [1:0] aluop2_type,
    input wire [5:0] alucode,
    input wire [31:0] srcreg1,
    input wire [31:0] srcreg2,
    input wire [31:0] imm,

    output wire [31:0] alu_result,
    output wire br_taken
);
wire [31:0] op1, op2;

function [31:0] op;
    input [1:0] aluop_type;
    input [31:0] srcreg;
    input [31:0] imm;
    input [31:0] pc;
    case(aluop_type)
        `OP_TYPE_IMM:op=imm;
        `OP_TYPE_PC:op=pc;
        default:op=srcreg;
    endcase
endfunction

assign op1 = op(aluop1_type, srcreg1, imm, pc);
assign op2 = op(aluop2_type, srcreg2, imm, pc);

alu alu_body(
    .alucode(alucode),
    .op1(op1),
    .op2(op2),

    .alu_result(alu_result),
    .br_taken(br_taken)
);
endmodule
