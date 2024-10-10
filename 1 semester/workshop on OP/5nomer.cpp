#include <stdio.h>
#include <locale.h>
#define N 10
int main() {
    setlocale(LC_ALL, "");
    int dl, vis, c = 0, M[N][N] = { 0 };;
    do {
        c += 1;
        if (c > 1) {
            printf("Значение введено некорректно \n");
            printf("Введите значение больше предыдущего \n");
        }
        printf("Введите высоту матрицы - ");
        scanf_s("%d", &vis);
        printf("Введите длину матрицы - ");
        scanf_s("%d", &dl);
    } while (dl < 1 or vis < 1);
    printf("\n");
    printf("Твоя матрица: \n");
    for (int i = 0; i < vis; i++) {
        for (int j = 0; j < dl; j++) {
            M[i][j] = 0;
            printf("%4d", M[i][j]);
        }
        printf("\n");
    }
    return 0;
}