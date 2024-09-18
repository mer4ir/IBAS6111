#include <stdio.h>
#include <locale.h>
 int main()
 {
   int one, two;
   setlocale(LC_ALL, "");
   printf("Введите два числа: ");
   scanf("%d %d", &one, &two);
   if (one > two)
   {
    printf("%d > %d", one, two);
   }
   else if (one < two)
   {
    printf("%d < %d", one, two);
   }
   else
   {
    printf("%d  =  %d", one, two);
   }
   return 0;
 }    