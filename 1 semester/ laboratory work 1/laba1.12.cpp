#include <stdio.h>
#include <locale.h>
#define ssize 10

int main()
{
    setlocale(LC_ALL, "");
    //Вводим и проверяем правильность ввода порядка матрицы(ограничения от 1 до 10 не включительно)//
    int size; int cor = 0;
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
        printf("Введите порядок матрицы: ");
        scanf("%d", &size);
        printf("\n");
    }while (size < 1 or size > 10);
    int A[ssize][ssize] = {0};
    printf("-----------------------------");
    //Вводим элементы матрицы//
    for (int i = 0; i < size; i += 1)
    {
        for (int j = 0; j < size; j += 1)
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
    //Вывод исходной матрицы//
    for (int i = 0; i < size; i += 1)
    {
        for (int j = 0; j < size; j += 1)
        {
            printf("%5d", A[i][j]);
        }
        printf("\n");
    }

    printf("-----------------------------");
    printf("\n");
    printf("Готоая матрица");
    printf("\n");
    printf("-----------------------------");
    printf("\n");
    int mn = 100;
    //Ищем минимальный элемент на главной диагонали//
    for (int i = 0; i < size; i += 1)
    {
        if (mn > A[i][i])
        {
            mn = A[i][i];
        }
    }
    int mx = 0;
    //Ищем максимальный элемент на побочной диагонали//
    for (int i = 0, x = size-1; i < size; i += 1, x -= 1)
    {
        if (mx < A[i][x])
        {
            mx = A[i][x];
        }
    }
    //Увеличиваем элементы матрицы, находящиеся ниже побочной диагонали, на максимальный элемент побочной диагонали//
    //Уменьшаем элементы матрицы, находящиеся выше побочной диагонали, на минимальный элемент главной диагонали//
    //Выводим получившуюся матрицу//
    for (int i = 0; i < size; i += 1) 
    {
        for (int j = 0; j < size; j += 1) 
        {
            if (j > (size-i-1)) 
            {
                printf("%5d", A[i][j]+mx);
            }
            else if (j < (size-i)-1) 
            {
                printf("%5d", A[i][j]-mn);
            }    
            else
            {
                printf("%5d", A[i][j]);
            }
        }
        printf("\n");
    }
}
