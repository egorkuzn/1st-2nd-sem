#include <math.h>
#include <stdio.h>
double arctg(double x, double e) {
	double summ= x;
	double curm = x;
	int i = 1;
	while (fabs(curm) >= e) {
		curm *= i;
		i += 2;
		curm *= -x * x / i;
		summ += curm;
	}

	return summ;
}
void main() {
	double eee,xxx;
	scanf("%lf%lf", &xxx, &eee);
	printf("%0.5lf", arctg(xxx, eee));
}