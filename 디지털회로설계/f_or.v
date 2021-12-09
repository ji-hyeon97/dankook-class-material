module f_or (B,A,Q);
    input B,A;
	output Q;
	assign Q = B | A;
endmodule