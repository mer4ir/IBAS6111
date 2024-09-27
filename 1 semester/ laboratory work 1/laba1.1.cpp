#include <stdio.h>
#define n 10

int main() {
	int chr[n][n] = { 0 };
	int vect[n*n] = { 0 };
	int N = 0, d = 0; char p = { 0 };
	do {
		printf("input width and height of the matrix(0<N<10): ");
		scanf_s("%d", &N);
	} while (N > 10 || N < 0);
	printf("would you like to fill matrix yourself?(1 - yes/ 0 - no): ");
	scanf_s("%c", &p);
	scanf_s("%c", &p);
	/*заполнение матрицы*/
	if (p == 'y') {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				printf("input element[%d][%d] = ", i, j);
				scanf_s("%d", &chr[i][j]);
			}
		}
	}
	else{
		int t = 1;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				chr[i][j] = t; t++;
			}
		}
	}
	/*вывод матрицы в двухмерном виде*/
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("%4d", chr[i][j]);
		}
		printf("\n");
	}

	printf("\n");
	int c = 0;
	/*вывод матрицы в одномерном виде при N нечетной*/
	if (N % 2 == 1) {
		if (N == 1) { printf("%4d", chr[0][0]); }
		else {
			do {
				int x = d, y = d;
				do {
					vect[c] = chr[x][y];
					c++;
					y++;
					
				} while (y < N - 1 - d);
				do {
					vect[c] = chr[x][y];
					c++;
					x++;
				} while (x < N - 1 - d);
				do {
					vect[c] = chr[x][y];
					c++;
					y--;
				} while (y > 0 + d);
				do {
					vect[c] = chr[x][y];
					c++;
					x--;
				} while (x > 1 + d);
				vect[c] = chr[x][y];
				c++;
				d++;
			} while (d != N / 2);
			vect[c] = chr[N / 2][N / 2];
		}
	}
	/*при N четной*/
	else {
		do {
			int x = d, y = d;
			do {
				vect[c] = chr[x][y];
				c++;
				y++;

			} while (y < N - 1 - d);
			do {
				vect[c] = chr[x][y];
				c++;
				x++;
			} while (x < N - 1 - d);
			do {
				vect[c] = chr[x][y];
				c++;
				y--;
			} while (y > 0 + d);
			do {
				vect[c] = chr[x][y];
				c++;
				x--;
			} while (x > 1 + d);
			d++;
			if (d != N / 2) {
				vect[c] = chr[x][y];
				c++;
			}
		} while (d != N / 2);
	}


	for (int i=0; i < N * N; i++) {
		printf("%4d", vect[i]);
	}

	return 0;
}
