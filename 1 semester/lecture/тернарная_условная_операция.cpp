//Для целых чисел
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

//Для строки
#include <stdio.h>

int main()
{
    int a;
    printf("Введите а: ");
    scanf("%d", &a);
    const char* sm = (a%2==0) ? "Чётное" : "Нечётное";
    printf("Число а - %s ", sm);
    return 0;
}
