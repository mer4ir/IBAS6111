#include <locale.h>
#include <stdio.h> 
#include <string.h> 

void do_sot(int a, char* vivod) {
    const char* ed[] = { "", "один ", "два ", "три ", "четыре ", "пять ",
                   "шесть ", "семь ", "восемь ", "девять " };
    const char* doped[] = { "десять ", "одиннадцать ", "двенадцать ",
                           "тринадцать ", "четырнадцать ", "пятнадцать ",
                           "шестнадцать ", "семнадцать ", "восемнадцать ",
                           "девятнадцать " };
    const char* des[] = { "", "десять ", "двадцать ", "тридцать ",
                           "сорок ", "пятьдесят ", "шестьдесят ",
                           "семьдесят ", "восемьдесят ", "девяносто " };
    if (a > 9 and a < 20) {
        strcat(vivod, doped[a % 10]);
    }
    else if (a >= 20 and a < 100) {
        strcat(vivod, des[a / 10]);
        strcat(vivod, ed[a % 10]);
    }
    else if (a >= 0 and a < 10) {
        strcat(vivod, ed[a]);
    }
}


void do_tis(int a, char* vivod) {

    const char* sot[] = { "", "сто ", "двести ", "триста ",
                               "четыреста ", "пятьсот ", "шестьсот ",
                               "семьсот ", "восемьсот ", "девятьсот " };

    if (a > 99) {
        strcat(vivod, sot[a / 100]);
    }
    do_sot(a % 100, vivod);
}

void do_sottis(int a, char* vivod) {
    const char* tis[] = { "", "одна тысяча ", "две тысячи ", "три тысячи ", "четыре тысячи ", "пять тысяч ",
                   "шесть тысяч ", "семь тысяч ", "восемь тысяч ", "девять тысяч " };

    if (a < 10000) {
        strcat(vivod, tis[a / 1000]);
        do_tis(a % 1000, vivod);
    }
    else if (a > 9999 and a < 21000) {
        do_sot(a / 1000, vivod);
        strcat(vivod, "тысяч ");
        do_tis(a % 1000, vivod);
    }
    else if (a > 20999 and a < 100000) {
        do_sot(a / 1000 - ((a / 1000) % 10), vivod);
        strcat(vivod, tis[((a / 1000) % 10)]);
        do_tis(a % 1000, vivod);
    }
}


void do_mil(int a, char* vivod) {

    const char* sot[] = { "", "сто ", "двести ", "триста ",
                               "четыреста ", "пятьсот ", "шестьсот ",
                               "семьсот ", "восемьсот ", "девятьсот " };
    if (a > 99999 and a < 1000000) {
        do_tis(a / 1000 - ((a / 1000) % 100), vivod);
        if (a / 1000 > 99 and a / 1000 < 110) {
            strcat(vivod, "тысяч ");
        }
        do_sottis(a % 100000, vivod);
    }
}
//доп условие на миллионы тк не работает с 20 тыс
void do_sotmln(int a, char* vivod) {
    const char* tis[] = { "", "один миллион ", "два миллиона ", "три миллиона ", "четыре миллиона ", "пять миллионов ",
                   "шесть миллионов ", "семь миллионов ", "восемь миллионов ", "девять миллионов " };

    if (a < 10000000) {
        strcat(vivod, tis[a / 1000000]);
        a = a % 1000000;
        if (a > 999 and a < 100000) {
            do_sottis(a, vivod);
        }
        else if (a > 99999 and a < 1000000) {
            do_mil(a, vivod);
        }
    }
    else if (a > 9999999 and a < 21000000) {
        do_sot(a / 1000000, vivod);
        strcat(vivod, "миллионов ");
        a = a % 1000000;
        if (a > 999 and a < 100000) {
            do_sottis(a, vivod);
        }
        else if (a > 99999 and a < 1000000) {
            do_mil(a, vivod);
        }
    }
    else if (a > 20999999 and a < 100000000) {
        do_sot(a / 1000000 - ((a / 1000000) % 10), vivod);
        strcat(vivod, tis[((a / 1000000) % 10)]);
        a = a % 1000000;
        if (a > 999 and a < 100000) {
            do_sottis(a, vivod);
        }
        else if (a > 99999 and a < 1000000) {
            do_mil(a, vivod);
        }
    }
}


void do_milrd(int a, char* vivod) {
    if (a > 99999999 and a < 1000000000) {
        do_tis(a / 1000000 - ((a / 1000000) % 100), vivod);
        if (a / 1000000 > 99 and a / 1000000 < 110) {
            strcat(vivod, "миллионов ");
        }
        do_sotmln(a % 100000000, vivod);
    }
}

void nado(int a, char* vivod) {
    if (a == 0) {
        strcat(vivod, "нуль");
    }
    else if (a > 0 and a < 100) {
        do_sot(a, vivod);
    }
    else if (a > 99 and a < 1000) {
        do_tis(a, vivod);
    }
    else if (a > 999 and a < 100000) {
        do_sottis(a, vivod);
    }
    else if (a > 99999 and a < 1000000) {
        do_mil(a, vivod);
    }
    else if (a >= 1000000 and a < 100000000) {
        do_sotmln(a, vivod);
    }
    else if (a >= 100000000 and a < 1000000000) {
        do_milrd(a, vivod);
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
