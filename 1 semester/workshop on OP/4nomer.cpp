#include <stdio.h>
#include <locale.h>
#define n 10
int main() {
  setlocale(LC_ALL, "");
  int a, b[n] = { 0 };
  printf("Введите количество символов для массива: ");
  scanf_s("%d", &a);
  for (int i = 0; i < a; i++) {
    printf("Введите символ: ");
    scanf_s("%d", &b[i]);
  }
  printf("---------------------------\n");
  printf("Массив - ");
  for (int i = 0; i < a; i++) {
    printf(" %d", b[i]);
  }
  printf("\n---------------------------\n");
  printf("Обратный массив - ");
  for (int i = 0; i < a; i++) {
    printf(" %d", b[a - i - 1]);
  }
  printf("\n---------------------------\n");
  return 0;
}