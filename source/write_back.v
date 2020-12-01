module writeback(
	inout clk,
	input rstd, 
	input	[31:0] nextpc,
	output reg [31:0]	pc
	);
	
	always @(negedge rstd or posedge clk) begin
		if (rstd == 0)	pc <= 8000;
		else if (clk == 1)	pc <= nextpc;
	end
endmodule
