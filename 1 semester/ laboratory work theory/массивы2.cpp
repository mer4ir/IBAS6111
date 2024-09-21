#include <stdio.h>
#include <locale.h>
#define maxn 20

int main()
{
    int lng; int A[maxn];
    setlocale(LC_ALL, "");
    do 
    {  
    printf("Введите число N <= %d:  ", maxn);
    scanf("%d", &lng);
    }
    while (lng > maxn or lng < 0);
    for (int i = 0; i < lng; i += 1)
    {
        A[i] = i;
    }
    for (int i = 0; i < lng; i += 1)
    {
        printf("%d, ", A[i]);
    }
}