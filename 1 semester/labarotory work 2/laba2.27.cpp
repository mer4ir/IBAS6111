#include <stdio.h>
#include <stdlib.h>
#define size 8

// Функция, которая выводит шахматную доску
void PB(char b[size][size])
{
    for (int i = 0; i < size; i += 1)
    {
        for (int j = 0; j < size; j += 1)
        {
            printf("%c ", b[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Проверка, можно ли разместить ферзя в позиции(g, v)
int IS(char b[size][size], int g, int v)
{
    int i, j;
    // Проверяем текущий столбец
    for (i = 0; i < g; i += 1)
    {
        if (b[i][v] == 'Q')
        {
            return 0;
        }
    }

    // Проверяем левую диагональ
    for (i = g, j = v; i >= 0 && j >= 0; i -= 1, j -= 1)
    {
        if (b[i][j] == 'Q')
        {
            return 0;
        }
    }

    // Проверяем правую диагональ
    for (i = g, j = v; i >= 0 && j < size; i -= 1, j += 1)
    {
        if (b[i][j] == 'Q')
        {
            return 0;
        }
    }

    return 1;
}

//Функция для правильного расположения 8 ферзей
int SNQ(char b[size][size], int g, int sr, int sc)
{
    if (g == size)
    {
        return 1;
    }
    if (g == sr)
    {
        return SNQ(b, g+1, sr, sc);
    }
    for (int v = 0; v < size; v += 1)
    {
        if (IS(b, g, v))
        {
            b[g][v] = 'Q'; // Ставим ферзя
            // Переходим на другой ряд
            if (SNQ(b, g + 1, sr, sc))
            {
                return 1;
            }
            b[g][v] = '.'; // Убираем ферзя
        }
    }
    return 0;
}

int main()
{
    char b[size][size];
    for (int i = 0; i < size; i += 1)
    {
        for (int j = 0 ; j < size; j += 1)
        {
            b[i][j] = '.';
        }
    }
    int sg, sv;
    // Ввод начальной позиции ферзя
    do
    {
        printf("Введите начальную позицию для первого ферзя (строка и столбец от 0 до 7):\n");
        scanf("%d %d", &sg, &sv);
    } while ((sg < 0 or sg > 7) or (sv < 0 or sv > 7));
    // Ставим первого ферзя
    b[sg][sv] = 'Q';
    // Выводим начальную доску
    printf("Начальная доска:\n");
    PB(b);
    // Запускаем решение с позиции следующего ряда
    if (!SNQ(b, 0, sg, sv)) 
    {
        printf("Нет решения!\n");
    } 
    else 
    {
        printf("Решение: \n");
        PB(b);
    }
    return 0;
}
