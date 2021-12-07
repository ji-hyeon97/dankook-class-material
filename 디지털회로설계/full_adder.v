module full_adder(input In1, In2, Cin, output Sum, Cout);

assign Sum = (In1 ^ In2) ^ Cin;

assign Cout = (In1 & In2) | (In2 & Cin) | (Cin & In1);

endmodule