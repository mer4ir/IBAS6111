#include <stdio.h>
#include <locale.h>
#include <math.h>

//функция основная, с точностью
long double znach(long double x, long double toch) {
    int n = 1;
    float y = x*x*x / (float)3;
    float yy = y;
    while (fabs(y) > toch)
    {
        n += 1;
        y *= (3 * n - 2) * x*x*x / (n * 3);
        yy += y;
    }
    yy = 1 - yy;
    return yy;
}

//функция проверки
long double rz(long double x) {
    return (1 / (pow((1 + pow(x, 3)), (1 / (float)3))));
}

//вывод значений и функций
void fun(long double nach, long double kon, long double shag, long double toch) {
    long double x = nach + shag;
    printf("\n%-10s %-20s %-20s \n", "x", "f(x) обычный", "f(x) проверка");
    while (x <= kon) {
        float raz = rz(x);
        float zn = znach(x, toch);
        printf("%-10lf %-20.7lf %-20.7lf \n", x, zn, raz);
        x += shag;
    }
}

//начальные значения
int main() {
    setlocale(LC_ALL, "");
    while (1) {
        int cont;
        long double nach, kon, shag, toch, c = 0, cc = 0, ccc = 0, cccc = 0;
        do {
            c++;
            if (c > 1) {
                printf("Введите более адекватное значение\n");
            }
            printf("Введите начало функции [-1;1] : \n");
            scanf("%lf", &nach);
        } while ((nach < (long double)-1) or (nach > (long double)1));
        do {
            cc++;
            if (cc > 1) {
                printf("Введите более адекватное значение\n");
            }
            printf("Введите конец функции [-1;1] : \n");
            scanf("%lf", &kon);
        } while ((kon < (long double)-1) or (kon > (long double)1));
        do {
            ccc++;
            if (ccc > 1) {
                printf("Введите более адекватное значение\n");
            }
            printf("Введите шаг для функции (0;2) : \n");
            scanf("%lf", &shag);
        } while ((shag <= (long double)0) or (shag > (long double)2));
        do {
            cccc++;
            if (cccc > 1) {
                printf("\nВведите более адекватное значение\n");
            }
            printf("\nВведите точность для функции более 0: \n");
            scanf("%lf", &toch);
        } while (toch <= (long double)0);
        fun(nach, kon, shag, toch);
        printf("Хотите продолжать? (1/0)\n");
        scanf("%d", &cont);
        if (cont != 1) {
            break;
        }
    }
    return 0;
}
