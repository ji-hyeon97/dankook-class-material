module half_subtractor(input X, Y, output D, B);

assign D = X ^ Y;

assign B = ~X & Y;

endmodule