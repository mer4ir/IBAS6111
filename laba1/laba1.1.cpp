#include <stdio.h>
#define n 10

int main() {
	int chr[n][n] = { 0 };
	int N = 0, t = 1, d = 0;
	printf("input width and height of the matrix: ");
	scanf_s("%d", &N);
	printf("\n");

	/*заполнение матрицы*/
	for (int i = 0; i < N; i++ ) {
		for (int j = 0;j < N;j++){
			chr[i][j] = t;
			t++; } }  
	/*вывод матрицы в двухмерном виде*/
	for (int i = 0; i < N; i++) {
			for (int j = 0;j < N;j++) {
				printf("%4d", chr[i][j]); }
			printf("\n"); }

	printf("\n");
	/*вывод матрицы в одномерном виде при N нечетной*/
	if (N%2 == 1) {
			if (N == 1) { printf("%4d", chr[0][0]); }
			else {
				do {
					int x = d, y = d;
					do {
						printf("%4d", chr[x][y]);
						y++; } while (y < N - 1 - d);
					do {
						printf("%4d", chr[x][y]);
						x++; } while (x < N - 1 - d);
					do {
						printf("%4d", chr[x][y]);
						y--; } while (y > 0 + d);
					do {
						printf("%4d", chr[x][y]);
						x--; } while (x > 1 + d);
					printf("%4d", chr[x][y]);
					d++; } while (d != N / 2);
				printf("%4d", chr[N / 2][N / 2]); } }
	/*при N четной*/
	else {
			do {
				int x = d, y = d;
				do {
					printf("%4d", chr[x][y]);
					y++; } while (y < N - 1 - d);
				do {
					printf("%4d", chr[x][y]);
					x++; } while (x < N - 1 - d);
				do {
					printf("%4d", chr[x][y]);
					y--; } while (y > 0 + d);
				do {
					printf("%4d", chr[x][y]); 
					x--; } while (x > 1 + d);
				d++;
				if (d != N / 2) {
					printf("%4d", chr[x][y]); } } while (d != N / 2); }	

	return 0; }
