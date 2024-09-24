#include <stdio.h>
#include <locale.h>
#define N 10
int main() {
    setlocale(LC_ALL, "");
    int dl, shir, schet = 0, pr = 0;
    //вводим ширину и длину матрицы//
    do {
        pr += 1;
        if (pr > 1) {
            printf("Значение введено некорректно \n");
            printf("Введите значение больше предыдущего \n");
        }
        printf("Введите ширину матрицы - ");
        scanf_s("%d", &shir);
        printf("Введите длину матрицы - ");
        scanf_s("%d", &dl);
    } while (dl < 1 or dl > 10 or shir < 1 or shir > 10);
    //задаем числа для матрицы//
    printf("\n");
    printf("Придумай числа для твоей матрицы: \n");
    int M[N][N] = { 0 };
    for (int i = 0; i < shir; i++) {
        for (int j = 0; j < dl; j++) {
            printf("M[%d][%d] - ", i, j);
            scanf_s("%d", &M[i][j]);
        }
    }
    printf("\n");
    //проверяем сколько будет 3 на 3 матриц//
    for (int i = 0; i < shir; i++) {
        for (int j = 0; j < dl; j++) {
            if ((M[i][j] == 0) and (M[i][j + 1] == 1) and (M[i][j + 2] == 0) and (M[i + 1][j] == 1) and (M[i + 1][j + 1] == 0) and (M[i + 1][j + 2] == 1) and (M[i + 2][j] == 0) and (M[i + 2][j + 1] == 1) and (M[i + 2][j + 2] == 0)) {
                schet++;
            }
        }
    }
    //вывод саамой матрицы и числа 3 на 3 матриц//
    printf("Это количество 3 на 3 матриц - %d\n", schet);
    printf("\n");
    printf("Вот и сама матрица \n");
    for (int i = 0; i < shir; i++) {
        for (int j = 0; j < dl; j++) {
            printf("%4d", M[i][j]);
        }
        printf("\n");
    }
    return 0;
}
