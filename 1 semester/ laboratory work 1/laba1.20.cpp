#include <stdio.h>
#include <locale.h>
#define size1 10
#define size2 10

int main()
{
    int mxsm = 20;
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
        scanf("%d", &lng);
        printf("Введите число столбцов массива: ");
        scanf("%d", &width);
        printf("\n");
    }while (width < 1 or lng < 1 or width > 10 or lng > 10);
    int A[size1][size2] = {0};
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
    printf("Готовая матрица");
    printf("\n");
    printf("-----------------------------");
    printf("\n");
    for (int i = 0; i < lng; i += 1)
    {
        int sm = 0;
        for (int j = 0; j < width; j += 1)
        {
            sm += A[i][j];
        }
        int k = 0;  
        int k1 = 0;
        int l = 0;
        int o = 0;
        if (mxsm < sm)
        {
            while (k <= (width-1))
            {
                A[i][k] = 0;
                printf("%5d ", A[i][k]);
                k += 1;
            }
            printf("\n");
        }
        else
        {
            while (k1 <= (width-1))
            {
                A[i][o] = -(A[i][o]);
                printf("%5d ", A[i][o]);
                o += 1;
                k1 += 1;
            }
            printf("\n");
        }
    }
    printf("-----------------------------");
}
