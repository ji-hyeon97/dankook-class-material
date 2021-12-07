`timescale 1ns/1ns
module functions_tb;
	reg a, b;
	wire f_and, f_or, f_not, f_nand, f_nor, f_xor, f_xnor;
	functions f (a,b, f_and, f_or, f_not, f_nand, f_nor, f_xor, f_xnor);
	initial begin
	$display ("time\ta\tb\tand\tor\tnot\tnand\tnor\txor\txnor");
	a = 0;
	b = 0;
	# 5 $finish;
end

initial begin
	$monitor ("%2d:\t%b\t%b\t%b\t%b\t%b\t%b\t%b\t%b\t%b",
	            $time, a, b, f_and, f_or, f_not, f_nand, f_nor, f_xor, f_xnor);
end
always #1 a = !a;
always #2 b = !b;
endmodule