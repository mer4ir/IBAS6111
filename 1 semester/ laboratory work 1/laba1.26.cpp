#include <stdio.h>
#include <locale.h>
#define s1 10
#define s2 10
int main()
{
	setlocale(LC_ALL, "");
	int ln; int wd; int cor1 = 0; int cor2 = 0;
	do
	{
		printf("\n");
		cor1 += 1;
		if (cor1 > 1)
		{
			printf("Некорректные значения");
			printf("\n");
			printf("Введите значения в пределах от 1 до %d для строк и от 1 до %d для столбцов: ", s1, s2);
			printf("\n");
		}
		printf("Введите количество строк массива, max=%d: ", s1);
		scanf_s("%d", &ln);
	} while (ln < 1 or ln >s1);
	do
	{
		printf("\n");
		cor2 += 1;
		if (cor2 > 1)
		{
			printf("Некорректные значения");
			printf("\n");
			printf("Введите значения в пределах от 1 до %d для строк и от 1 до %d для столбцов: ", s1, s2);
			printf("\n");
		}
		printf("Введите количество столбцов массива, max=%d: ", s2);
		scanf_s("%d", &wd);
	} while (wd < 1 or wd > s2);
	int A[s1][s2] = { 0 };
	printf("\n");
	for (int i = 0; i < ln; i += 1)
	{
		for (int j = 0; j < wd; j += 1)
		{
			printf("\n");
			printf("Введите значение элемента:");
			printf("A[%d][%d]=", i, j);
			scanf_s("%d", &A[i][j]);
		}
	}
	printf("\n");
	printf("\n");
	printf("Исходная матрица");
	printf("\n");
	for (int i = 0; i < ln; i += 1)
	{
		for (int j = 0; j < wd; j += 1)
		{
			printf("%5d", A[i][j]);
		}
		printf("\n");
	}

	int mx = A[0][0]; int mn = A[0][0];
	int countmx = 0; int countmn = 0;
	for (int i = 0; i < ln; i += 1)
	{
		for (int j = 0; j < wd; j += 1)
		{
			if (mx == A[i][j])
			{
				countmx += 1;
			}
			if (mx < A[i][j])
			{
				mx = A[i][j];
				countmx = 1;
			}
			if (mn == A[i][j])
			{
				countmn += 1;
			}
			if (mn > A[i][j])
			{
				mn = A[i][j];
				countmn = 1;
			}
		}
	}
	printf("\n");
	printf("\n");
	printf("Максимальный элемент: %d, количество максимальных элементов: %d", mx, countmx);
	printf("\n");
	printf("Минимальный элемент: %d, количество минимальных элементов: %d", mn, countmn);
}
