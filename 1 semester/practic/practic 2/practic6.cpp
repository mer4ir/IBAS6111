#include <stdio.h>
#include <locale.h>
int main() {
  int a;
  int suma;
  float sr;
  scanf_s("%d", &a);
  int c = 1;
  suma = a;
  while (a != 0) {
    scanf_s("%d", &a);
    suma += a;
    c++;
    sr = suma / (float) c;
  }
  printf("Количество элементов: %d. Сумма всех элементов: %d. Среднее арифмитическое: %.3f", c, suma, sr);
  return 0;
}
