#include <stdio.h>
 int main()
 {
   int one, two;
   printf("Введите два числа: ");
   scanf("%d %d", &one, &two);
   if (one > 0 and two > 0)
   {
    printf("1 четверть");
   }
   else if (one > 0 and two < 0)
   {
    printf("4 четверть");
   }
   else if (one < 0 and two > 0)
   {
    printf("2 четверть");
   }
   else if (one < 0 and two < 0)
   {
    printf("3 четверть");
   }
   else if (one == 0 and two == 0)
   {
    printf("начало координат");
   }
   else if (one == 0 and two != 0)
   {
    printf("ось оX");
   }
   else if (one != 0 and two == 0)
   {
    printf("ось оY");
   }
   return 0;
 }    