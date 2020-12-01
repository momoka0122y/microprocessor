`include "define.vh"

module ram(clk, alucode, r_addr, r_data, w_addr, w_data);
input clk;
input [5:0] alucode; //0:sb 1:sh 2:sw それ以外：何もしない
input  [31:0] r_addr, w_addr;
input  [31:0] w_data;

output [31:0] r_data;
reg [31:0] mem [0:32768];//32bitのレジスタが32個(アドレスは5bit)

initial $readmemh("/Users/momoka/git/microprocessor/benchmarks/Coremark/data.hex", mem);

assign r_data = ((r_addr >= 32'h10000) && (r_addr <32'h20000))?mem[(r_addr-32'h10000)>>2]:32'b0;

always @(posedge clk) begin
if ((w_addr >= 32'h10000) && (w_addr <32'h20000)) begin
  case (alucode)
    `ALU_SW: mem[(w_addr-32'h10000)>>2] <= w_data; //クロックと同期して書き込まれる
    `ALU_SH: begin
      case (w_addr[1:0])
        2'b00: mem[(w_addr-32'h10000)>>2][15:0] <= w_data[15:0];
        2'b01: mem[(w_addr-32'h10000)>>2][23:8] <= w_data[15:0];
        default : mem[(w_addr-32'h10000)>>2][31:16] <= w_data[15:0];
      endcase
    end
    `ALU_SB:begin
      case (w_addr[1:0])
        2'b00:mem[(w_addr-32'h10000)>>2][7:0] <= w_data[7:0];
        2'b01:mem[(w_addr-32'h10000)>>2][15:8] <= w_data[7:0];
        2'b10:mem[(w_addr-32'h10000)>>2][23:16] <= w_data[7:0];
        default : mem[(w_addr-32'h10000)>>2][31:24] <= w_data[7:0];
      endcase
    end
    default : ;
  endcase
  end else ;
end


endmodule
