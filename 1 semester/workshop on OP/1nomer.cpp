#include <stdio.h>
#include <locale.h>
int main() {
  setlocale(LC_ALL, "");
  int a, kol, sum = 0, c = 0;
  printf("Введите количество слагаемых: \n");
  scanf_s("%d", &kol);
  do {
    printf("-------------------------\n");
    printf("Введите слагаемое: ");
    scanf_s("%d", &a);
    sum += a;
    c++;
  } while (c < kol);
  printf("-------------------------\n");
  printf("Сумма слагаемых будет равна: %d", sum);
  return 0;
}