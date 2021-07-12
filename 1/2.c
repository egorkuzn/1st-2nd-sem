#include <stdio.h>
#include <math.h>
#pragma warning(disable: 4996);
int main() {
	float h, m, s;
	double res;
	scanf("%f\n%f\n%f", &h, &m, &s);
	res = (double)h * m * s;
	printf("%lf", res);
	return 0;
}