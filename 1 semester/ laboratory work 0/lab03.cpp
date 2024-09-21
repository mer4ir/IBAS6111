#include <stdio.h>
#include <locale.h>

int main()

{
    setlocale(LC_ALL, "");
    printf("Привет мир!");
    return 0;
}
