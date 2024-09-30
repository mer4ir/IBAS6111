#include <stdio.h>
#define size 10

int main()
{
    int A[size] = {-8, 5, 4, -3, 7, 6, 1, -5, 0, 3};
    for (int i = 0; i < size; i += 1)
    {
        if (A[i] % 2 == 0) continue; // Если число A[i] делится на 2(то есть оно чётное), то мы его пропускаем
        printf("%d, ", A[i]);
    }
    return 0;
}

// Если число A[i] - чётное, то мы его пропускаем
// Функция выведет все нечётные элементы
