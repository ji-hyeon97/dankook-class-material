module half_subtractor_tb;
   reg X, Y;
   wire D, B;
   half_subtractor uut (.X(X), .Y(Y), .D(D), .B(B));
   
   initial begin
      $dumpfile("half_subtractor.vcd");
	  $dumpvars(0, half_subtractor_tb);
	 
	  X = 0; Y = 0;
      #10 X= 1; 
	  #10 Y = 1; 
	  #10 $finish;
	end
endmodule