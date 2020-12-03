module writeback(
	inout clk,
	input rst, 
	input	[31:0] nextpc,
	output reg [31:0]	pc
	);
	
	always @(negedge rst or posedge clk) begin
		if (rst == 0)	pc <= 8000;
		else if (clk == 1)	pc <= nextpc;
	end
endmodule
