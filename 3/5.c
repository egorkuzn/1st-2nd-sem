#include <stdio.h>
#pragma warning(disable:4996)
void main() {
	static short mass[1000001];
	long n;
	scanf("%li", &n);
	for (long i = 2; i <= n; ++i)
	{
		if (mass[i] != 1) {
			printf("%d ", i);
			for (long j = 0; j <= n; j += i)
				mass[j] = 1;
		}
	}
}