#include <stdio.h>
 int main()
 {
   int one, two;
   printf("Введите два числа: ");
   scanf("%d %d", &one, &two);
   if (two == 0)
   {
    printf("Деление на 0");
   }
   else
   {
    double c = (double)one / two;
        printf("%d/%d=%f", one, two, c);
   }
   return 0;
 }    