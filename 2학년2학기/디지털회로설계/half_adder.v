module half_adder
(
     input in1, in2, 
	 output count, sum);

assign sum = in1 ^ in2;

assign count = in1 & in2;

endmodule