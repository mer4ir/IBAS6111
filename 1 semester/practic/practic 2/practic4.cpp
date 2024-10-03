#include <stdio.h>
#include <locale.h>
#include <math.h>

int main()
{
    int nd = 0, kd = 0;
    double shag = 0;
    do
    {
        printf("Введите начало диапозона: ");
        scanf("%d", &nd);
        printf("Введите конец диапозона: ");
        scanf("%d", &kd);
        printf("Введите шаг: ");
        scanf("%lf", &shag);
    } while (nd > kd and shag > 0);
    double i = nd;
    double k;
    do
    {
        k = 3*pow(i, 2) - 7*i + 4;
        i += shag;
        printf("%f ", k);
    } while (i < kd);
    return 0;
}
