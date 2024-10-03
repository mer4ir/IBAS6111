#include <stdio.h>
#include <locale.h>

int main()
{
    char symb, prsymb;
    int sum = 0, ssum = 0;
    printf("Введите символ, количество вхождений которого хотите посчитать: \n");
    scanf("%c", &prsymb);
    while (true)
    {
        printf("Введите следующий элемент последовательности \n");
        printf("Для завершения программы введите '.'!\n");
        scanf(" %c", &symb);
        if (symb != '.')
        {
            if (symb == prsymb)
            {
                ssum += 1;
            }
        }
        else 
        {
            break;
        }
        sum += 1;
    }
    printf("Всего символов в строке - %d. Символ %c встретился %d раз(а).", sum, prsymb, ssum);
}
