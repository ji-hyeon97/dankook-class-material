// `timescale 1 ns/10 ps
//`include "half.adder.v"
module half_adder_tb;
   reg in1, in2;
   wire count, sum;
   // localparam period = 20;
   
   half_adder uut (.in1(in1), .in2(in2), .count(count), .sum(sum));
   
   initial begin
      $dumpfile("half_adder.vcd");
	  $dumpvars(0, half_adder_tb);
	  $monitor ("%t, in1= %d | in2 = %d | sum = %d | count = %d", $time, in1, in2, sum, count);
	 
	  in1 = 0; in2 = 0;
      #10 in1= 1; 
	  #10 in2 = 1; 
	  #10 $finish;
	end
endmodule