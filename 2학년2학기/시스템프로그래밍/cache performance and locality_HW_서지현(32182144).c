#include<stdio.h>
#include <malloc.h>
#include<time.h>

int main() {

	int  i, j, k;
	double start, end;

	int x;
	int y;
	int*** A;
	A = (int***)malloc(sizeof(int**) * 500);
	for (x = 0; x < 500; x++){

		A[x] = (int**)malloc(sizeof(int*) * 500); 
	
		for (y = 0; y < 500; y++){
			A[x][y] = (int*)malloc(sizeof(int) * 500); 			
		}
	}
	start = (double)clock() / CLOCKS_PER_SEC;

	for (i = 0; i < 500; i++) {
		for (j = 0; j < 500; j++) {
			for (k = 0; k < 500; k++) {
				A[i][j][k] = i + j + k;
			}
		}
	}
	end = (double)clock() / CLOCKS_PER_SEC;

	printf("조건 a 프로그램 수행 시간 :%f\n", (end - start));
	for (x = 0; x < 500; x++){
		for (y = 0; y < 500; y++){
			free(A[x][y]); 
		}
	}

	for (x = 0; x < 500; x++){
		free(A[x]); 
	}
	free(A);

	A = (int***)malloc(sizeof(int**) * 500);
	for (x = 0; x < 500; x++){

		A[x] = (int**)malloc(sizeof(int*) * 500);

		for (y = 0; y < 500; y++)		{
			A[x][y] = (int*)malloc(sizeof(int) * 500);
		}
	}
	start = (double)clock() / CLOCKS_PER_SEC;

	for (k = 0; k < 500; k++) {
		for (i = 0; i < 500; i++) {
			for (j = 0; j < 500; j++) {
				A[i][j][k] = i + j + k;
			}
		}
	}
	end = (double)clock() / CLOCKS_PER_SEC;

	printf("조건 b 프로그램 수행 시간 :%f\n", (end - start));

	for (x = 0; x < 500; x++){
		for (y = 0; y < 500; y++){
			free(A[x][y]); 
		}
	}

	for (x = 0; x < 500; x++){
		free(A[x]); 
	}
	free(A);

	A = (int***)malloc(sizeof(int**) * 500);
	for (x = 0; x < 500; x++){

		A[x] = (int**)malloc(sizeof(int*) * 500); 

		for (y = 0; y < 500; y++){
			A[x][y] = (int*)malloc(sizeof(int) * 500); 
		}
	}

	start = (double)clock() / CLOCKS_PER_SEC;

	for (k = 0; k < 500; k++) {
		for (j = 0; j < 500; j++) {
			for (i = 0; i < 500; i++) {
				A[i][j][k] = i + j + k;
			}
		}
	}
	end = (double)clock() / CLOCKS_PER_SEC;

	printf("조건 c 프로그램 수행 시간 :%f\n", (end - start));

	for (x = 0; x < 500; x++){
		for (y = 0; y < 500; y++){
			free(A[x][y]); 
		}
	}

	for (x = 0; x < 500; x++){
		free(A[x]);
	}
	free(A);

	return 0;
}