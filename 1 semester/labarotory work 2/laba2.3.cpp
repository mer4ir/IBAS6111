#include <stdio.h>
#include <locale.h>
#include <math.h>

//функция основная, с точностью
long double znach(long double x, long double toch) {
    int n = 1;
    float y = pow(x, 3) / (float)3;
    float yy = y;
    while (fabs(y) > toch)
    {
        n += 1;
        y *= (3 * n - 2) * pow(x, 3) / (n * 3);
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
    long double nach = -1;
    long double  kon = 1;
    long double shag, toch, c = 0, cc = 0;

    do {
        c++;
        if (c > 1) {
            printf("Введите более адекватное значение\n");
        }
        printf("Введите шаг для функции (0;2) : \n");
        scanf("%lf", &shag);
    } while ((shag <= (long double)0) or (shag > (long double)2));
    do {
        cc++;
        if (cc > 1) {
            printf("\nВведите более адекватное значение\n");
        }
        printf("\nВведите точность для функции более 0: \n");
        scanf("%lf", &toch);
    } while (toch <= (long double)0);
    fun(nach, kon, shag, toch);
    return 0;
}
