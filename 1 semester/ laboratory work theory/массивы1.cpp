#include <stdio.h>
#include <locale.h>

int main()
{
    int lng;
    printf("Введите размерность массива:");
    scanf("%d", &lng);
    setlocale(LC_ALL, "");
    int A[lng];
    for (int i = 0; i < lng; i += 1)
    {
        A[i] = i;
    }
    for (int i = 0; i < lng; i += 1)
    {
        printf("%d, ", A[i]);
    }
}