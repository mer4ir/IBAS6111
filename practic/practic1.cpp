#include <stdio.h>
 int main()
 {
   char name[32] = {0};
   int age;
   printf("Введите ваше имя: ");
   scanf("%s", name);
   printf("Введите ваш возраст: ");
   scanf("%d", &age);
   printf("Привет! %s %d летний.", name, age);
   return 0;
 }