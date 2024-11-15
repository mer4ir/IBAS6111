#include <locale.h>
#include <stdio.h> 
#include <string.h> 

void viv(int a, char* vivod) {
    const char* ed[] = { "", "один ", "два ", "три ", "четыре ", "пять ",
               "шесть ", "семь ", "восемь ", "девять " };
    const char* doped[] = { "десять ", "одиннадцать ", "двенадцать ",
                           "тринадцать ", "четырнадцать ", "пятнадцать ",
                           "шестнадцать ", "семнадцать ", "восемнадцать ",
                           "девятнадцать " };
    const char* des[] = { "", "десять ", "двадцать ", "тридцать ",
                           "сорок ", "пятьдесят ", "шестьдесят ",
                           "семьдесят ", "восемьдесят ", "девяносто " };
    const char* sot[] = { "", "сто ", "двести ", "триста ",
                               "четыреста ", "пятьсот ", "шестьсот ",
                               "семьсот ", "восемьсот ", "девятьсот " };
    const char* tis[] = { "тысяч ", "одна тысяча ", "две тысячи ", "три тысячи ", "четыре тысячи ", "пять тысяч ",
               "шесть тысяч ", "семь тысяч ", "восемь тысяч ", "девять тысяч " };
    const char* mil[] = { "", "один миллион ", "два миллиона ", "три миллиона ", "четыре миллиона ", "пять миллионов ",
                   "шесть миллионов ", "семь миллионов ", "восемь миллионов ", "девять миллионов " };
    if (a > 0 and a < 10) {
        strcat(vivod, ed[a]);
    }
    else if (a > 9 and a < 20) {
        strcat(vivod, doped[a - 10]);
    }
    else if (a > 19 and a < 100) {
        strcat(vivod, des[a / 10]);
        viv(a % 10, vivod);
    }
    else if (a > 99 and a < 1000) {
        strcat(vivod, sot[a / 100]);
        viv(a % 100, vivod);
    }
    else if (a > 999 and a < 10000) {
        strcat(vivod, tis[a / 1000]);
        viv(a - 1000, vivod);
    }
    else if (a > 9999 and a < 20000) {
        strcat(vivod, doped[a / 1000-10]);
        strcat(vivod, "тысяч ");
        viv(a % 1000, vivod);
    }
    else if (a > 19999 and a < 100000) {
        strcat(vivod, des[a/10000]);
        strcat(vivod, tis[a / 1000 % 10]);
        viv(a % 10000, vivod);
    }
    else if (a > 99999 and a < 1000000) {
        strcat(vivod, sot[a / 100000]);
        viv(a % 100000, vivod);
    }
    else if (a > 999999 and a < 10000000) {
        strcat(vivod, mil[a / 1000000]);
        viv(a - 1000000, vivod);
    }
}

void nado(int a, char* vivod) {
    if (a == 0) {
        strcat(vivod, "нуль");
    }
    else {
        viv(a, vivod);
    }
    vivod++;
    printf("---------------------------------------------------------------\n");
    printf("Введите число на письме: \n");
    printf("[ \%s\]\n", vivod);
    printf("---------------------------------------------------------------\n");
}

int main() {
    setlocale(LC_ALL, "");
    char vivod[100] = " ";
    int a, c = 0;
    do {
        c++;
        if (c >= 2) {
            printf("Ну вообще-то правильно будет от 0 до 999999999\n");
            printf("А ну, еще раз пробуй\n");
        }
        printf("---------------------------------------------------------------\n");
        printf("Введите число в цифрах - ");
        scanf_s("%d", &a);
    } while (a < 0 or a >= 1000000000);
    nado(a, vivod);
    return 0;
}
