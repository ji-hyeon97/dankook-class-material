module f_xnor (B,A,Q);
    input B,A;
	output Q;
	assign Q = ~(B ^ A);
endmodule