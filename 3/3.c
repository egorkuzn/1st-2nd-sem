#include <stdio.h>
#pragma warning(disable:4996)
void main() {
	static long counts[10001];
	for (long i = 0; i < 10001; ++i)
		counts[i] = 0;
	long n;
	scanf("%li", &n);
	for (long i = 0; i < n; ++i) {
		long c;
		scanf("%li", &c);
		++counts[c];
	}
	for (long i = 0; i < 10001; ++i)
		if (counts[i] != 0)
			printf("%li: %li\n", i, counts[i]);
}