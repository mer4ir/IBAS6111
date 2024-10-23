#include <stdio.h>
#include <locale.h>
#include <math.h>

void od(int chi) {
    char A[10][20] = { "","один", "два","три","четыре","пять","шесть","семь","восемь","девять" };
    if (chi > 0) {
        printf("%s ", A[chi]);
    }
    else if (chi < 0) {
        printf("минус %s ", A[abs(chi)]);
    }
    else if (chi == 0) {
        printf("%s", A[0]);
    }
}

void des(int chi) {
    int chi2 = abs(chi);
    char A[10][20] = { "","один", "два","три","четыре","пять","шесть","семь","восемь","девять" };
    char B[9][30] = { "одиннадцать", "двенадцать", "тринадцать", "четырнадцать", "пятнадцать", "шестнадцать", "семнадцать", "восемнадцать", "девятнадцать" };
    char C[9][30] = { "десять","двадцать","тридцать","сорок","пятьдесят","шестьдесят","семьдесят","восемьдесят", "девяносто" };
    if (chi > 0) {
        if (chi > 10 and chi < 20) {
            printf("%s ", B[chi - 11]);
        }
        else if (chi >= 20 or chi == 10) {
            printf("%s %s ", C[chi / 10 - 1], A[chi % 10]);
        }
    }
    else {
        if (chi2 > 10 and chi2 < 20) {
            printf("минус %s ", B[chi2 - 11]);
        }
        else if (chi2 >= 20 or chi2 == 10) {
            printf("минус %s %s ", C[chi2 / 10 - 1], A[chi2 % 10]);
        }
    }
}

void sot(int chi) {
    char D[9][30] = {"сто", "двести", "триста", "четыреста", "пятьсот", "шестьсот", "семьсот", "восемьсот", "девятьсот"};
    int chi2 = chi;
    chi = abs(chi);
    chi = chi % 100;
    if (chi2 > 0) {
        printf("%s ", D[chi2 / 100 - 1]);
    }
    else if (chi2 < 0) {
        printf("минус %s ", D[abs(chi2) / 100 - 1]);
    }
    if (chi < 10) {
        od(chi);
    }
    else if (chi >= 10) {
        des(chi);
    }
    
}

void htis(int chi) {
        if (chi > 0 and chi < 10) {
            od(chi);
        }
        else if (chi >= 10 and chi < 100) {
            des(chi);
        }
        else if (chi >= 100 and chi < 1000) {
            sot(chi);
        }
}

void tis(int chi) {
    char E[3][30] = { "одна тысяча", "тысячи", "тысяч" };
    char EE[3][30] = { "две", "три", "четыре" };
    int chi2 = chi;
    chi = abs(chi);
    int chi3 = chi % 1000;
    if (chi2 > 0) {
        if (chi >= 1000 and chi < 2000) {
            printf("%s ", E[0]);
            htis(chi3);
        }
        else if (chi >= 2000 and chi < 5000) {
            printf("%s ", EE[chi / 1000 - 2]);
            printf("%s ", E[1]);
            htis(chi3);
        }
        else if (chi >= 5000 and chi < 10000) {
            od(chi / 1000);
            printf("%s ", E[2]);
            htis(chi3);
        }
    }
    else if (chi2 < 0) {
        if (chi >= 1000 and chi < 2000) {
            printf("минус %s ", E[0]);
            htis(chi3);
        }
        else if (chi >= 2000 and chi < 5000) {
            printf("минус %s ", EE[chi / 1000 - 2]);
            printf("%s ", E[1]);
            htis(chi3);
        }
        else if (chi >= 5000 and chi < 10000) {
            od(chi2 / 1000);
            printf("%s ", E[2]);
            htis(chi3);
        }
    }
}

int main() {
    setlocale(LC_ALL, "");
    char A[10][20] = { "ноль","один", "два","три","четыре","пять","шесть","семь","восемь","девять" };
    char B[9][30] = { "одиннадцать", "двенадцать", "тринадцать", "четырнадцать", "пятнадцать", "шестнадцать", "семнадцать", "восемнадцать", "девятнадцать" };
    char C[9][30] = { "десять","двадцать","тридцать","сорок","пятьдесят","шестьдесят","семьдесят","восемьдесят", "девяносто" };
    int chi;
    bool cc = true;
    while (cc == true) {
        printf("\n");
        printf("Введите число в пределах [-9999;9999] : ");
        scanf_s("%d", &chi);
        if (chi > -9999 or chi < 9999) {
            if (abs(chi) >= 0 and abs(chi) < 10) {
                printf("\n");
                od(chi);
                printf("\n");
            }
            else if (abs(chi) >= 10 and abs(chi) < 100) {
                printf("\n");
                des(chi);
                printf("\n");
            }
            else if (abs(chi) >= 100 and abs(chi) < 1000) {
                printf("\n");
                sot(chi);
                printf("\n");
            }
            else if (abs(chi) >= 1000 and abs(chi) < 10000) {
                printf("\n");
                tis(chi);
                printf("\n");
            }
        }
    }
    return 0;
}