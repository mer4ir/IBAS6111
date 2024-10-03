
#include <stdio.h>
#include <locale.h>
int main() 
{
  int a;
  int suma;
  float sr;
  printf("Введите первый элемент последовательности: \n");
  scanf("%d", &a);
  int c = 0;
  suma = a;
  while (a != 0) 
  {
    printf("Введите следующий элемент последовательности:");
    printf("\n");
    printf("Для завершения программы введите 0\n");
    scanf("%d", &a);
    suma += a;
    c += 1;
    sr = suma / (float) c;
  }
  printf("Количество элементов: %d. Сумма всех элементов: %d. Среднее арифмитическое: %.3f", c, suma, sr);
  return 0;
}
