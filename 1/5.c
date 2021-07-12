#include <stdio.h>
#include <math.h>
#pragma warning(disable:4996)
int main() {
	int x[4], y[4], sx[4], sy[4];
	double s[3], p = 0;
	for (short i = 1; i <= 3; ++i) {
		scanf("%d%d", &x[i], &y[i]);
	}
	sx[1] = x[1] - x[2]; sy[1] = y[1] - y[2];
	sx[2] = x[3] - x[2]; sy[2] = y[3] - y[2];
	sx[3] = x[3] - x[1]; sy[3] = y[3] - y[1];
	for (short i = 0; i < 3; ++i) {
		s[i] = (double)sqrt(pow(sx[i + 1], 2) + pow(sy[i + 1], 2));
		p += s[i];
	}
	printf("%.3lf\n", p);
	p /= 2.0;
	double S = p;
	for (short i = 0; i < 3; ++i) {
		S *= (p - s[i]);
	}
	S = sqrt(S);
	printf("%.3lf", S);
	return 0;
}