#include <stdio.h>
#include <locale.h>

int main()
{
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
        scanf("%d", &lng);
        printf("Введите число столбцов массива: ");
        scanf("%d", &width);
        printf("\n");
    }while (width < 1 or lng < 1 or width > 10 or lng > 10);
    setlocale(LC_ALL, "");
    int A[lng][width];
    printf("-----------------------------");
    for (int i = 0; i < lng; i += 1)
    {
        for (int j = 0; j < width; j += 1)
        {
            printf("\n");
            printf("Введите значение элемента: ");
            printf("A[%d][%d]=", i, j);
            scanf("%d", &A[i][j]);
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

    for (int j = 0; j < width; j += 1)
    {
        if (j%2==0)
        {
            for (int i = 0; i < lng; i += 1)
            {
                printf("%d ", A[i][j]);
            }
        }
        else
        {
            for (int i = (lng-1); i > -1; i = i - 1)
            {
                printf("%d ", A[i][j]);
            }
        }
    }
    printf("\n");
    printf("-----------------------------");
}
