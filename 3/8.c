#include <stdio.h>
#pragma warning (disable:4996);
int main() {
	static int mass[100000];
	long n, k;
	scanf("%li %li", &n, &k);
	for (long i = k % n; i < n; ++i)
		scanf("%d", &mass[i]);
	for (long i = 0; i < k % n; ++i)
		scanf("%d", &mass[i]);
	for (long i = 0; i < n; ++i)
		printf("%d ", mass[i]);
	return 0;
}