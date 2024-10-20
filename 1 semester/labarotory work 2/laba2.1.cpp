#include <stdio.h>
#include <math.h>

long long int fac(int n)
{
	long long int c = 1;
	if (n % 2 == 0)
	{
		for (long i = 2; i <= n; i = i+2)
		{
			c = c * i;
		}
	}
	else
	{
		for (int i = 3; i <= n; i = i+2)
		{
			c = c * i;
		}
	}
	return(c);
}

int acc(double z1, double z2, double e)
{
	if (fabs(z1 - z2) > e)
	{
		return(1);
	}
	else
	{
		return(0);
	}
}

double sigma(double x,double e)
{
	long double c = 0, z1,z2;
	int n = 1;
	z2 = pow(-1, n) * (long double(fac(2 * n - 1)) / long double(fac(2 * n))) * (pow(x, 2 * n + 1) / long double(2 * n + 1));
	do {
		z1 = z2; n++; c = c + z1;
		z2 = pow(-1, n) * (long double(fac(2 * n - 1)) / long double(fac(2 * n))) * (pow(x, 2 * n + 1) / long double(2 * n + 1));
	} while (acc(z1, z2, e));
	return(c);
}

int main()
{
	double a, b, h, e;
	printf("start[0, 1] ");
	scanf_s("%lf", &a);
	printf("end[start, 1] ");
	scanf_s("%lf", &b);
	printf("step ");
	scanf_s("%lf", &h);
	printf("accuracy ");
	scanf_s("%lf", &e);
	printf("x        f(x)'     f(x)\n");
	for (double x = a; x <= b; x = x + h)
	{
		double c = sigma(x, e);
		printf("%8lf  %8lf  %8lf\n", x, x + c, log(x + sqrt(1 + x*x)));
	}
	return(0);
}
