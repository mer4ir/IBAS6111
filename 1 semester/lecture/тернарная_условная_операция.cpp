#include <stdio.h>

int main()
{
    int a, b, min;
    printf("Введите а и b: ");
    scanf("%d %d", &a, &b);
    min = (a < b) ? a : b;
    printf("Минимальное значение - %d ", min);
    return 0;
}
