#include <stdio.h>
#include <math.h>

double sigma(double x, double e)
{
	double c = 0, z1, z2;
	double n = 1;
	z2 =   x * x* x / double( - 6);
	do {
		z1 = z2; n++; c += z1;
		z2 = -1 * z1 * ((n * 2 - 1) / (2* n)) * x * x * ((2 * n - 1) / (2 * n + 1));
	} while (fabs(z2) > e);
	return(c);
}

int main()
{
loop1:
	double a, b, h, e;
start:
	printf("start[0, 1] ");
	scanf_s("%lf", &a);
	if (a > 1 or a < 0) {
		goto start;
	};
end:
	printf("end[start, 1] ");
	scanf_s("%lf", &b);
	if (b > 1 or b < a) {
		goto end;
	};
	printf("step ");
	scanf_s("%lf", &h);
accuracy:
	printf("accuracy ");
	scanf_s("%lf", &e);
	if (e <= 0) {
		goto accuracy;
	}
	printf("x        f(x)'     f(x)\n");
	double x;
	for (x = a; x < b; x = x + h)
	{
		double c = sigma(x, e);
		printf("%8lf  %8lf  %8lf\n", x, x + c, log(x + sqrt(1 + x * x)));
	}
	double c = sigma(b, e);
	printf("%8lf  %8lf  %8lf\n", b, b + c, log(b + sqrt(1 + b * b)));
	int q = 0;
	printf("if you want to restart input 1. ");
	scanf_s("%d", &q);
	if (q == 1) { 
		printf("\n");
		goto loop1; 
	};
	return(0);
}
