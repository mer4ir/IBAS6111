#include <stdio.h> 
#include <locale.h> 
int main() {
    // начало общей части 
    setlocale(LC_ALL, "RU");
    int n = 0, m = 0;
    float A[50][50];
    // Ввод количества строк 
    printf("Введите число строк до 100 \n");
    scanf_s("%d", &n);
    while (n < 2 or n>100) {
        printf("Введите верное значение \n");
        scanf_s("%d", &n);
    }
    // Ввод количества столбцов 
    printf("Введи число столбцов\n");
    scanf_s("%d", &m);
    while (m < 2 || m>100) {
        printf("Введи верное значение \n");
        scanf_s("%d", &m);
    }
    // Ввод матрицы 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("A[%d,%d]= ", i, j);
            scanf_s("%f", &A[i][j]);
        }
    }
    // Вывод матрицы  
    printf("Вы ввели матрицу:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%12f", A[i][j]);
        }
        printf("\n");
    }
    //Переменные 
    double c = 0, r = 0, s = 0;
    int k = m * n;
    printf("Введи величину, на которую будет отличаться число \n");
    scanf_s("%lf", &r);
    //Меняем матрицу
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            s = s + A[i][j];
        }
    }
    double sr = s / k;
    printf("Сумма всех элементов матрицы равна %lf \nКоличество элементов равно %d \nСреднее значение равно %lf \n", s, k, sr);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if ((A[i][j] - sr) > r || (sr - A[i][j]) > r)
            {
                A[i][j] = 0;
            }
        }
    }
    printf("Измененная матрица: \n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%12f", A[i][j]);
        }
        printf("\n");
    }
    return 0;
}