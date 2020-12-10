module fetch(pc, ir);
  input [31:0] pc;
  output [31:0] ir;
  reg [31:0] ir_mem [0:32767];
  
  initial $readmemh("/Users/momoka/git/microprocessor/benchmarks/tests/ControlTransfer/code.hex", ir_mem);
//    initial $readmemh("/home/denjo/microprocessor/benchmarks/Coremark_for_Synthesis/code.hex", ir_mem);
//   initial $readmemh("/home/denjo/microprocessor/benchmarks/tests/Uart/code.hex", ir_mem);


  assign ir = ir_mem[pc[31:2]];

endmodule
