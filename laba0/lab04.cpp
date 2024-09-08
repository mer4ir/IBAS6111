#include <locale.h>
#include <stdio.h>

int main()

{
    int a, b;
    setlocale(LC_ALL, "");
    printf("Введите первое число: ");
    scanf("%d", &a);
    printf("Введите второе число: ");
    scanf("%d", &b);
    if (b == 0)
    {
        printf("Деление на 0");
    }
    else
    {
        double c = (double)a / b;
        printf("%d/%d=%f", a, b, c);
    }
    return 0;
}
