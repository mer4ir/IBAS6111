#include <stdio.h>
#include <locale.h>
#define a 10
int main() {
  setlocale(LC_ALL, "");
  //переменные для создания массива//
  int razmer, pom = 0;
  //переменные чтобы найти большее и меньшее число//
  int max = -99999999, min = 99999999, znach;
  //запрашиваем размерность массива, при этом она должна быть больше 0 и меньше 10//
  do {
    pom += 1;
    if (pom > 1) {
      printf("Нужно значение больше \n");
      printf("Введите значение еще раз \n");
    }
    printf("Введите длину и ширину массива - \n");
    scanf_s("%d", &razmer);
  } while (razmer < 1 or razmer > 10);
  printf("Введите числа для матрицы - \n");
  //создаем виртуальный массив ( мы его не будем выводить, он просто существует в памяти ноута)//
  int co[a][a] = { 0 };
  int t = 1;
  for (int i = 0; i < razmer; i++) {
    for (int j = 0; j < razmer; j++) {
      printf("co[%d][%d] - ", i, j);
      scanf_s("%d", &co[i][j]);
      //ищем большее число//
      if (co[i][j] > max) {
        max = co[i][j];
      }
      //ищем меньшее число//
      if (co[i][j] < min) {
        min = co[i][j];
      }
    }
  }
  //думаю и так понятно, что делаем//
  printf("Самое большое число -  %d \n", max);
  printf("Самое маленькое число - %d \n", min);
  znach = (max + min) / 2;
  printf("Среднее арифметическое этих чисел будет: ((%d) + (%d))/2 = %d \n", max, min, znach);
  printf("Получившаяся матрица \n");
  //создаем условие для задания//
  if (znach > -1) {
    for (int i = 0; i < razmer; i++) {
      //здесь задаю новые переменные, читобы поменять побочную и основную диагональ//
      //одна принимает значение побоной, другая основной и меняем их местами(перезаписываем)//
      int os = co[i][i];
      int pob = co[i][razmer - i - 1];
      co[i][i] = pob;
      co[i][razmer - 1 - i] = os;
      for (int j = 0; j < razmer; j++) {
        printf("%4d", co[i][j]);
      }
      printf("\n");
    }
  }
  else {
    for (int i = 0; i < razmer; i++) {
      for (int j = 0; j < razmer; j++) {
        //условие в котором мы не трогаем элементы основной диагонали//
        if (i != j) {
          printf("%4d", co[j][i]);
        }
        else {
          printf("%4d", co[i][j]);
        }
      }
      printf("\n");
    }
  }
  
}