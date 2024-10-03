#include <stdio.h>
#include <locale.h>

int main()
{
    int num;
    do
    {
        printf("Введите целое положительное число: ");
        scanf("%d", &num); 
    } while (num < 1);
    int i = 2;
    int k;
    int sch = 0;
    do
    {
        if (num % i == 0)
        {
            sch += 1;
        }
        i += 1;
    } while (i <= num/2);
    if (sch == 0)
        {
            printf("Число %d - простое", num);
        }
        else (printf("Число %d - составное", num));
    return 0;   
}
