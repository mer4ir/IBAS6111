#include <stdio.h>
#include <locale.h>
#define a 10

int main() 
{
    setlocale(LC_ALL, "");
    int razmer, pom = 0;
    int max = -99999999, min = 99999999, znach;
    do 
    {
        pom += 1;
        if (pom > 1) 
        {
            printf("Некоректные значения! \n");
            printf("Введите значение от 1 до 10 \n");
        }
        printf("Введите размерность матрицы - ");
        scanf("%d", &razmer);
  } while (razmer < 1 or razmer > 10);
  printf("Введите элементы матрицы: \n");
  int A[a][a] = { 0 };
  int t = 1;
  for (int i = 0; i < razmer; i++) 
  {
    for (int j = 0; j < razmer; j++) 
    {
        printf("A[%d][%d]: ", i, j);
        scanf("%d", &A[i][j]);
        if (A[i][j] > max) 
        {
            max = A[i][j];
        }
        if (A[i][j] < min) 
        {
            min = A[i][j];
        }
    }
  }
  printf("\n");
  printf("Исходная матрица: \n");
  for (int i = 0; i < razmer; i += 1)
  {
    for (int j = 0; j < razmer; j += 1)
    {
        printf("%5d", A[i][j]);
    }
    printf("\n");
    }
    printf("\n");
    printf("Минимальный элемент: %d \n", min);
    printf("Максимальный элемент:  %d \n", max);
    znach = (max + min) / 2;
    printf("Среднее арифметическое этих чисел будет: ((%d) + (%d))/2 = %d \n", max, min, znach);
    printf("\n");
    printf("Получившаяся матрица \n");
    if (znach > 0) 
    {
        for (int i = 0; i < razmer; i++) 
        {
            int os = A[i][i];
            int pob = A[i][razmer - i - 1];
            A[i][i] = pob;
            A[i][razmer - 1 - i] = os;
            for (int j = 0; j < razmer; j++) 
            {
                printf("%5d", A[i][j]);
            }
            printf("\n");
        }
    }
    else if (znach < 0)
    {
        for (int i = 0; i < razmer; i++) 
        {
            for (int j = 0; j < razmer; j++) 
            {
                if (j > i) 
                {   
                    A[i][j] = -(A[i][j]);
                    printf("%5d", A[i][j]);
                }
                else
                {
                    printf("%5d", A[i][j]);
                }
            }
        printf("\n");
        }
    }
    else if (znach == 0)
    {
        for (int i = 0; i < razmer; i += 1)
        {
            for (int j = 0; j < razmer; j += 1)
            {
                printf("%5d", A[i][j]);
            }
            printf("\n");
        }
    }
}
