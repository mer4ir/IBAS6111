#include <stdio.h>
#include <locale.h>

int time, currtime = 0, cor = 0;
double prof, vx, vy, vz, x, y, z, ln, wd, dp;

void space(int cor) {
    setlocale(LC_ALL, "");
    do
    {
        printf("\n");
        cor += 1;
        if (cor > 1) {
            printf("Некорректные значения пространства");
            printf("\n");
        }
        printf("Введите длину пространства: ");
        scanf("%lf", &ln);
        printf("Введите ширину пространства: ");
        scanf("%lf", &wd);
        printf("Введите глубину пространства: ");
        scanf("%lf", &dp);
        printf("\n");
    } while (ln <= 0 or wd <= 0 or dp <= 0);
}

void startpos(int cor) {
    setlocale(LC_ALL, "");
    do
    {
        printf("\n");
        cor += 1;
        if (cor > 1)
        {
            printf("Некорректное положение");
            printf("\n");
        }
        printf("Введите начальное положение х: ");
        scanf("%lf", &x);
        printf("Введите начальное положение y: ");
        scanf("%lf", &y);
        printf("Введите начальное положение z: ");
        scanf("%lf", &z);
        printf("\n");
    } while (x<0 or x>ln or y< 0 or y>wd or z<0 or z>dp);
}
void speed() {
    setlocale(LC_ALL, "");
    printf("\n");
    printf("Введите скорость по  х: ");
    scanf("%lf", &vx);
    printf("Введите скорость по y: ");
    scanf("%lf", &vy);
    printf("Введите скорость по z: ");
    scanf("%lf", &vz);
}
void timeset(int cor) {
    setlocale(LC_ALL, "");
    do
    {
        printf("\n");
        cor += 1;
        if (cor > 1)
        {
            printf("Некорректное время");
            printf("\n");
        }
        printf("Введите время: ");
        scanf("%d", &time);
        printf("\n");
    } while (time <= 0);
}

void step(double *p, double *vp, double sp) {
    while (*p<0 or *p>sp) {
        if (*p >= sp) {
            *vp = *vp * -1;
            *p = sp - (*p - sp);
        }

        if (*p <= 0) {
            *vp = *vp * -1;
            *p = 0 + (0 - *p);
        }
    }
}

int main() {
    space(cor);
    startpos(cor);
    speed();
    timeset(cor);

    do {
        printf("%5d: (%11lf, %11lf, %11lf)\n", currtime, x, y, z);
        currtime++;
        x += vx;
        y += vy;
        z += vz;

        step(&x, &vx, ln);
        step(&y, &vy, wd);
        step(&z, &vz, dp);

    } while (currtime <= time);

    return(0);
}
