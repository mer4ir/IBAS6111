#include <stdio.h>
#include <locale.h>
#include <math.h>


//функция через ряд
float znach(float x, float toch)
{
    int n = 1;
    int qq = 1;
    int e = 1;
    float y = 1 - (pow(-1, n + 1) * (qq / pow(3, n) * e) * pow(x, 3 * n));
    float yy = y;
    while (fabs(y) > toch)
    {
        n += 1;
        int q = 3 * n - 2;
        qq *= q; //числитель
        e *= n; //факториал
        y = 1 - (pow(-1, n + 1) * (qq / pow(3, n) * e) * pow(x, 3 * n));
        yy += y;
    }
    return yy;
}


//вывод значений и функций
void fun(float nach, float kon, float shag, float toch) {
    setlocale(LC_ALL, "");
    float x = nach + shag;
    printf("%-10s %-20s %-20s \n", "x", "f(x) ряд", "f(x) полученные значения");
    while (x <= kon) {
        float raz = (1 / (pow(1 + pow(x, 3), (1 / (float) 3))));
        float zn = znach(x, toch);
        printf("%-10.3f %-20.7f %-20.7f \n", x, zn, raz);
        x += shag;
    }
}

//начальные значения
int main() {
    setlocale(LC_ALL, "");
    float nach = -1;
    float kon = 1;
    float shag, toch;
    printf("Введите шаг для функции: ");
    scanf_s("%f", &shag);
    printf("Введите точность для функции: ");
    scanf_s("%f", &toch);
    fun(nach, kon, shag, toch);
    return 0;
}