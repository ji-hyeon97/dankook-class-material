// `timescale 1 ns/10 ps
//`include "full_subtractor.v"

module full_subtractor_tb;
   reg X, Y, Z;
   wire D, B;
   full_subtractor uut (.X(X), .Y(Y), .Z(Z), .D(D), .B(B));
   
   initial begin
      $dumpfile("full_subtractor.vcd");
	  $dumpvars(0, full_subtractor_tb);
	  $monitor ("%t, X= %d | Y = %d | Z = %d | B = %d | D = %d", $time, X, Y, Z, B, D);
	 
	  X = 0; Y = 0; Z=0;
      #10 X = 1; 
	  #10 Y = 1; 
	  #10 Z = 1; 
	  #10 $finish;
	end
endmodule