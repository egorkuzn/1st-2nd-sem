#include <stdio.h>
#include <math.h>
#pragma warning(disable: 4996)
int main() {
	int a,k=1;
	double d,f=0.6;
	scanf("%d",&a);
	for (int i = 0; i < a; ++i) {
		scanf("%lf",&d);
		d = (double)sqrt(d*d) - (double)abs((int)d);
		if (d < f) {
			f = d;
			k = i + 1;
		}
		d = (double)1 - (double)d;
		if (d < f) {
			f = d;
			k = i + 1;
		}
	}
	printf("%d", k);
	return 0;
}