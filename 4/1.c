#include <stdio.h>
#include <math.h>
#pragma warning(disable:4996)
int ggc(int a, int b) {
	a = abs(a);
	b = abs(b);
	if (a == b)
		return a;
	else {
		if (a > b) {
			a += b;
			b = a - b;
			a -= b;
		}
		if (a == 0)
			return b;
		return ggc(a, b - a);
	}
}
int main() {
	int A, B;
	scanf("%d%d", &A, &B);
	A = ggc(A, B);
	printf("%d", A);
	return 0;
}