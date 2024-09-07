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
    if (a < b)
    {
        int c;
        c = a * a + b * b;
        printf("%d", c);
    }
    else if (a > b)
    {
        int c;
        c = a * a - b * b;
        printf("%d", c);
    }
    else
    {
        int c;
        c = 2 * a * b;
        printf("%d", c);
    }
    return 0;
}
