#include <stdio.h>
#include <locale.h>

int main()
{
    int lng; int width;
    printf("Введите длину массива:");
    scanf("%d", &lng);
    printf("Введите ширину массива:");
    scanf("%d", &width);
    setlocale(LC_ALL, "");
    int A[lng][width];
    for (int i = 0; i < lng; i += 1)
    {
        for (int j = 0; j < width; j += 1)
        {
            A[i][j] = i + j;
        }
    }
    for (int i = 0; i < lng; i += 1)
    {
        for (int j = 0; j < width; j += 1)
        {
            printf("%5d", A[i][j]);
        }
        printf("\n");
    }
}
