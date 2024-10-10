#include <stdio.h>
#include <locale.h>
int main() {
  setlocale(LC_ALL, "");
  int a, b = 1;
  printf("Введите число, чтобы узнать его факториал: ");
  scanf_s("%d", &a);
  for (int i = 1; i <= a; i++) {
    b *= i;
  }
  printf("-------------------------------\n");
  printf("Факториал заданного числа: %d", b);
  return 0;
}