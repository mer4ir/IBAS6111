#include <stdio.h>
#include <locale.h>
#define da 10
int main() {
    setlocale(LC_ALL, "");
    int raz, cor = 0;
    do {
        cor += 1;
        if (cor > 1) {
            printf("Значение введено некорректно \n");
            printf("Введите значение больше предыдущего \n");
        }
        printf("Введите размерность массива - \n");
        scanf_s("%d", &raz);
    } while (raz < 1 or raz > 10);
    printf("Введите саму матрицу - \n");
    int co[da][da] = { 0 };
    int t = 1;
    for (int i = 0; i < raz; i++) {
        for (int j = 0; j < raz; j++) {
            printf("co[%d][%d] - ", i, j);
            scanf_s("%d", &co[i][j]);
        }
    }
    printf("Вот и сама матрица \n");
    for (int i = 0; i < raz; i++) {
        int c = co[i][i];
        int v = co[i][raz - i - 1];
        co[i][i] = v;
        co[i][raz - 1 - i] = c;
        for (int j = 0; j < raz; j++) {
            if ((i < j && i + j < raz - 1) or (i > j && i + j > raz - 1)) {
                co[i][j] = 0;
                printf("%4d", co[i][j]);
            }
            else if ((j < i && i + j < raz - 1) or (j > i && i + j > raz - 1)) {
                co[i][j] = co[i][j] * 2;
                printf("%4d", co[i][j]);
            }
            else {
                printf("%4d", co[i][j]);
            }
        }
        printf("\n");
    }
    return 0;
}