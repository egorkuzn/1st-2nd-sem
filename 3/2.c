#include <stdio.h>
#pragma warning(disable:4996)
void main() {
	long n;
	scanf("%ld", &n);
	static unsigned int massiv[100000];
	for (long i = 0; i < n; ++i)
		scanf("%u", &massiv[i]);
	for (long i = 1; i <= n; ++i) {
		long count = 0;
		for (long j = i - 1; j < n; j += i)
			count += massiv[j];
		printf("%ld\n", count);

	}
}