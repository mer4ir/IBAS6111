#include <stdio.h>
#include <locale.h>
#define size1 10
#define size2 10

int main()
{
    setlocale(LC_ALL, "");
    int lng; int width; int cor = 0;
    do
    {
        printf("\n");
        cor += 1;
        if (cor > 1)
        {
            printf("-----------------------------");
            printf("\n");
            printf("Некоректные значения!");
            printf("\n");
            printf("Введите значения в пределах от 1 до 10!");
            printf("\n");
            printf("-----------------------------");
            printf("\n");
        }
        printf("Введите число строк массива: ");
        scanf_s("%d", &lng);
        printf("Введите число столбцов массива: ");
        scanf_s("%d", &width);
        printf("\n");
    } while (width < 1 or lng < 1 or width > 10 or lng > 10);
    int A[size1][size2] = { 0 };
    printf("-----------------------------");
    for (int i = 0; i < lng; i += 1)
    {
        for (int j = 0; j < width; j += 1)
        {
            printf("\n");
            printf("Введите значение элемента: ");
            printf("A[%d][%d]=", i, j);
            scanf_s("%d", &A[i][j]);
        }
    }
    printf("\n");
    printf("\n");
    printf("-----------------------------");
    printf("\n");
    printf("Исходная матрица");
    printf("\n");
    printf("-----------------------------");
    printf("\n");
    for (int i = 0; i < lng; i += 1)
    {
        for (int j = 0; j < width; j += 1)
        {
            printf("%5d", A[i][j]);
        }
        printf("\n");
    }

    printf("-----------------------------");
    printf("\n");
    printf("Готовый вектор");
    printf("\n");
    printf("-----------------------------");
    printf("\n");
    for (int i = 0; i < lng; i += 1)
    {
        int mx = 0; int nm = 0;
        for (int j = 0; j < width; j += 1)
        {
            if (mx < A[i][j])
            {
                mx = A[i][j];
                nm = j;
            }
        }
        printf("%d ", nm);
    }
    printf("\n");
    printf("-----------------------------");
}
