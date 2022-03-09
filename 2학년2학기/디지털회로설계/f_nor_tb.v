module f_nor_tb;
   reg B, A;
   wire Q;
   f_nor uut (B,A,Q);
   initial begin
      $dumpfile("f_nor.vcd");
	  $dumpvars(0, f_nor_tb);
	  $display("time\tB\tA\tQ");
	  $monitor("%2d:\t%b\t%b\t%b",
	      $time, B ,A, Q);
	  B = 0; A = 0;
      #10 B=0; A=1;
	  #10 B=1; A=0;
	  #10 B=1; A=1;
	  #10 $finish;
	end
endmodule