#include <stdio.h>
 int main()
 {
   int one, two;
   printf("Введите два число: ");
   scanf("%d %d", &one, &two);
   double c = (double)one + two;
   printf("%d+%d=%f", one, two, c);
   return 0;
 }    