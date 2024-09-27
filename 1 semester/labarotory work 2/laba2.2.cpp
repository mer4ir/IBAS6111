#include <stdio.h>
#include <locale.h>
#include <math.h>

// Функция для вычисления значения функции с использованием ряда
double fs(double x, double e)
{
    int n = 1;
    double t = pow(-1, n)*pow(x, 2*n+1)/(2*n*tgamma(2*n+2)); // первый член ряда
    double ss = t;
    while (fabs(t) > e) // продолжаем, пока член ряда больше e
    {
        n += 1;
        t = pow(-1, n)*pow(x, 2*n+1)/(2*n*tgamma(2*n+2)); // следующий член ряда
        ss += t;
    }
    return ss;
}

double fe(double x) // Точная функция для проверки
{
    return x*cos(x)-sin(x);
}

// Основная функция для получения таблицы значений
void gfv(double a, double b, double h, double e)
{
    double x = a;
    printf("%-10s %-20s %-20s \n", "x", "f(x) ряд", "f(x) полученные значения");
    while (x <= b)
    {
        double fsv = fs(x, e); // значение через ряд
        double fev = fe(x); // точное значение
        printf("%-10.5f %-20.10f %-20.10f \n", x, fsv, fev);
        x += h;
    }
}

int main()
{
    double a, b, h, e;
    // Вводим значения a, b, h, epsilon
    printf("Введите начало отрезка: ");
    scanf("%lf", &a);
    printf("Введите конец отрезка: ");
    scanf("%lf", &b);
    printf("Введите шаг: ");
    scanf("%lf", &h);
    printf("Введите точность: ");
    scanf("%lf", &e);
    // Получаем значения функции на отрезке
    gfv(a, b, h, e);
    return 0;
}
