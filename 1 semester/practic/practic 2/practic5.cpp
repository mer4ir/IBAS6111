#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <stdlib.h>

int main()
{
    int num;
    int count = 1;
    srand(time(NULL));
    int x = rand() % 100;
    do
    {
        printf("Введите число принадлежащее промежутку от 0 до 99: \n");
        scanf("%d", &num);
        if (x == num)
        {
            printf("Вы угадали!\n");
            printf("\n");
            printf("Количество попыток - %d\n", count);
        }
        else if (x < num)
        {
            count += 1;
            printf("Ваше число больше заданного! \n");
        }
        else if (x > num)
        {
            count += 1;
            printf("Ваше число меньше заданного! \n");
        }
    } while ((num < 0 and num > 99) or (x != num));
    return 0;
}
