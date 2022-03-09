module full_subtractor
(
      input X, Y, Z, 
	  output D, B
);

assign D = X ^ Y ^ Z;

assign B = ~X & (Y ^ Z) | Y & Z;

endmodule