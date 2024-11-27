#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <windows.h>
#define SIZE 255




int** create(const int n, const int m) {
	int** result;
	result = (int**)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) {
		result[i] = (int*)malloc(m * sizeof(int));
	}
	return result;
}

void readmat(int** a, const int n, const int m) {
	printf("Enter matrix elements:\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("a[%d][%d] = ", i, j);
			scanf("%d", &a[i][j]);
		}
	}
}

void printmat(int** a, const int n, const int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%5d ", a[i][j]);
		}
		printf("\n");
	}
}

void kesh(int** a, const int n, const int m) {
	for (int i = 0; i < n; i++) {
			free(a[i]);
		}
	free(a);
}

int main() {
	setlocale(LC_ALL, "");
	int n, m;
	printf("Введите количество строк");
	scanf("%d", &n);
	printf("Введите количество столбцов");
	scanf("%d", &m);
	int** a = create(n, m);
	readmat(a, n, m);
	printmat(a, n, m);
	free(a);
}
