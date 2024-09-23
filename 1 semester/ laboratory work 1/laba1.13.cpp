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
    int mn = 100000;
    //Ищем и выводим минимальный элемент матрицы/
    for (int i = 0; i < size; i += 1)
    {
        for (int j = 0; j < size; j += 1)
        {
            if (mn > A[i][j])
            {
                mn = A[i][j];
            }
        }
    }
    printf("-----------------------------");
    printf("\n");
    printf("Минимальный элемент матрицы:");
    printf("\n");
    printf("-----------------------------");
    printf("\n");
    printf("%d", mn);
    printf("\n");
    int mx = 0;
    //Ищем и выводим максимальный элемент матрицы//
    for (int i = 0; i < size; i += 1)
    {
        for (int j = 0; j < size; j += 1)
        {
            if (mx < A[i][j])
            {
                mx = A[i][j];
            }
        }
    }
    printf("-----------------------------");
    printf("\n");
    printf("Максимальный элемент матрицы:");
    printf("\n");
    printf("-----------------------------");
    printf("\n");
    printf("%d", mx);
    printf("\n");
    printf("-----------------------------");
    printf("\n");
    printf("Готоая матрица");
    printf("\n");
    printf("-----------------------------");
    printf("\n");
    int zero = 0;
    //Введём число на которое минимальный элемент матрицы должен делиться"
    int num = 3;
    //Проверяем минимальный элемент на чётность//
    //Если минимальный элемент чётный то, элементы, находящиеся выше главной диагонали, обнуляем//
    //Если минимальный элемент нечётный или кратен заданому числу то, элементам, находящимся выше побочной диагонали, меняем знак//
    //Выводим получившуюся матрицу//
    if (mn % 2 == 0)
    {
        for (int i = 0; i < size; i += 1) 
        {
            for (int j = 0; j < size; j += 1) 
            {
                if (j > i) 
                {
                    printf("%5d", zero);
                }    
                else
                {
                    printf("%5d", A[i][j]);
                }
            }
            printf("\n");
        }
    }
    else if (mn % 2 != 0 or mn % num == 0)
    {
        for (int i = 0; i < size; i += 1) 
        {
            for (int j = 0; j < size; j += 1) 
            {
                if (j < i) 
                {
                    printf("%5d", -A[i][j]);
                }
                else
                {
                    printf("%5d", A[i][j]);
                }
            }
            printf("\n");
        }
    }
}
