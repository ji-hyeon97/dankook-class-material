module f_nor (B,A,Q);
    input B,A;
	output Q;
	assign Q = ~(B|A);
endmodule