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
    int i = 1;
    int k;
    int sch = 1;
    do
    {
        if (num % i == 0)
        {
            k = i;
            printf("%d ", k);
            i += 1;
            sch += 1;
        }
        else (i += 1);
    } while (i <= num/2+1);
    printf("%d", num);
    printf("\n");
    printf("Кол-во делителей - %d", sch);
    return 0;   
}
