module f_not_tb;
   reg A;
   wire Q;
   f_not uut (A,Q);
   initial begin
      $dumpfile("f_not.vcd");
	  $dumpvars(0, f_not_tb);
	  $display("time\tA\tQ");
	  $monitor("%2d:\t%b\t%b",
	      $time,A, Q);
	  A=0;
      #10 A=1;
	  #10 $finish;
	end
endmodule