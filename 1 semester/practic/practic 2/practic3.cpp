#include <stdio.h>
#include <locale.h>

int main()
{
    int num;
    printf("Введите целое число: ");
    scanf("%d", &num); 
    if (num < 0)
    {
        num = -num;
        int k;
        int sm = 0;
        int count = 1;
        do
        {
            k = num % 10;
            count = count * k;
            sm += 1;
            num = num / 10;
        } while (num > 0);
        printf("Количество цифр - %d", sm);
        printf("\n");
        printf("Произведение равно %d", count);
    }
    else if (num == 0)
    {
        printf("Количество цифр - 1");
        printf("\n");
        printf("Произведение равно 0");
    }
    else if (num > 0)
    {
        int k;
        int sm = 0;
        int count = 1;
        do
        {
            k = num % 10;
            count = count * k;
            sm += 1;
            num = num / 10;
        } while (num > 0);
        printf("Количество цифр - %d", sm);
        printf("\n");
        printf("Произведение равно %d", count);
    }   
        return 0;   
}
