`timescale 1ns/100ps
`include "andOrNot.v"

module andOrNot_tb;

   wire A, B, C, D, E;
   integer k=0;
   
   assign {A,B,C} = k;
   andOrNot the_circuit(A, B, C, D, E);
   
   initial begin
      $dumpfile("andOrNot.vcd");
      $dumpvars(0, andOrNot_tb);
      
      for (k=0; k<8; k=k+1)
        #10 $display("done testing case %d", k);
        
      $finish;
      
   end
   
endmodule