#include <stdio.h>
#include <locale.h>
#include <math.h>


//функция с точностью
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

//функция для проверки
float rz(float x) {
    return (1 / (pow(1 + pow(x, 3), (1 / (float)3))));
}

//вывод значений и функций
void fun(float nach, float kon, float shag, float toch) {
    setlocale(LC_ALL, "");
    float x = nach + shag;
    printf("%-10s %-20s %-20s \n", "x", "f(x) ряд", "f(x) полученные значения");
    while (x <= kon) {
        float raz = rz(x);
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
    float shag, toch, c = 0, cc = 0;
    
    do {
        c++;
        if (c > 1) {
            printf("\nВведите более адекватное значение\n");
        }
        printf("\nВведите шаг для функции (0;2) : \n");
        scanf_s("%f", &shag);
    } while (shag <= (float) 0 or (int) shag > (float) 2);
    do {
        cc++;
        if (cc > 1) {
            printf("\nВведите более адекватное значение\n");
        }
        printf("\nВведите точность для функции более 0: \n");
        scanf_s("%f", &toch);
    } while ((int)toch <= (float) 0);
    fun(nach, kon, shag, toch);
    return 0;
}
