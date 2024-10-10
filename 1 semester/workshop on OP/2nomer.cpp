#include <stdio.h>
#include <locale.h>
int main() {
  setlocale(LC_ALL, "");
  int a, b = 0;
  printf("Введите число: ");
  scanf_s("%d", &a);
  while (a > 0) {
    b++;
    a = a / 10;
  }
  printf("Количество цифр в заданном числе: %d", b);
  return 0;
}