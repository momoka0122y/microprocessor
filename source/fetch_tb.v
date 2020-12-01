`include "fetch.v"

`define assert(name, signal, value) \
        if (signal !== value) begin \
            $display("ASSERTION FAILED in %s : signal is '0x%x' but expected '0x%x'!", name, signal, value); \
            $finish; \
        end else begin \
            $display("    signal == value"); \
        end

`define test(name, ex_ir) \
        $display("%s:", name); \
        `assert("result", ir, ex_ir) \
        $display("%s test passed\n", name); \

module fetch_tb;

    reg [31:0] pc;
    wire [31:0] ir;
    wire [31:0] ir_mem [0:32768];

    fetch fetch(
        .pc(pc)

		,.ir(ir));

    initial begin

        // -----------------------------
        // arithmetic operations
        // -----------------------------
        
        pc = 8192;
        #10;
        `test("name", 32'h0080006f)


        $display("all tests passed!");
    end

endmodule