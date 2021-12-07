module full_adder_tb;
   reg Cin, In1, In2;
   wire Cout, Sum;
   full_adder uut (.In1(In1), .In2(In2), .Cin(Cin), .Sum(Sum), .Cout(Cout));
   
   initial begin
      $dumpfile("full_adder.vcd");
	  $dumpvars(0, full_adder_tb);
	 
	  Cin = 0; In1 = 0; In2 = 0;
      #10 In1 = 1; 
	  #10 In2 = 1; 
	  #10 Cin = 1;
	  #10 $finish;
	end
endmodule