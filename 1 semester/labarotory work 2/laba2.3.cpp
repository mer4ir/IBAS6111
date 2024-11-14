#include <stdio.h>
#include <locale.h>
#include <math.h>


long double fact(int n) {
    int i = 1;
    int s = 1;
    for (i; i < n; i++) {
        s *= i;
    }
    return s;
}

long double chisl(int n) {
    int i = 1;
    int s = 1;
    for (i; i < n; i++) {
        s *= 3 * n - 2;
    }
    return s;
}

//функция с точностью
long double znach(long double x, long double toch)
{
    int n = 1;
    float y = (pow(( - 1), n + 1) * (chisl(n) / (pow(3, n) * fact(n))) * pow(x, (3 * n)));
    float yy = y;
    while (fabs(y) > toch)
    {
        n += 1;
        y = (pow(( - 1), n + 1) * (chisl(n) / (pow(3, n) * fact(n))) * pow(x, (3 * n)));
        yy += y;
    }
    yy = 1 - yy;
    return yy;
}

//функция для проверки
long double rz(long double x) {
    return (1 / (pow(1 + pow(x, 3), (1 / (float)3))));
}

//вывод значений и функций
void fun(long double nach, long double kon, long double shag, long double toch) {
    setlocale(LC_ALL, "");
    long double x = nach + shag;
    printf("%-10s %-20s %-20s \n", "x", "f(x) ряд", "f(x) полученные значения");
    while (x <= kon) {
        float raz = rz(x);
        float zn = znach(x, toch);
        printf("%-10.3lf %-20.7lf %-20.7lf \n", x, zn, raz);
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
