#include <stdio.h>
#include <locale.h>
#define size1 10
#define size2 10

int main()
{
    setlocale(LC_ALL, "");
    int lng; int width; int cor = 0;
    int mxsm;
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
    } while (width < 1 or lng < 1 or width > 10 or lng > 10);


    int A[size1][size2] = { 0 };
    int B[size1] = {0};

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

    int msm;
    printf("Введите значение для сравнения: ");
    scanf("%d", &msm);
    printf("\n");
    printf("Вектор B - ");

    for (int i = 0; i < lng; i += 1)
    {
        for (int j = 0; j < width; j += 1)
        {
            B[i] += A[i][j];
        }
        
        printf("%d ", B[i]);
    }
    printf("\n");

    for (int i = 0; i < lng; i += 1)
    {
       if (B[i] >= msm)
        {
            //обнуляем строку i
            for (int j = 0; j < width; j += 1)
            {
                A[i][j] = 0;
            }
        }
        else
        {
           for (int j = 0; j < width; j += 1)
           {
               A[i][j] = -(A[i][j]);
           }
        }
    }

       printf("-----------------------------");
       printf("\n");
       printf("Готовая матрица");
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

}
