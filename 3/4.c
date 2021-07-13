#include <stdio.h>
#pragma warning(disable:4996)
void main() {
	long counts[2002];
	for (int i = 0; i < 2002; ++i)
		counts[i] = 0;
	long n;
	scanf("%li", &n);
	for (long i = 0; i < n; ++i) {
		int count;
		scanf("%d", &count);
		if (count >= 0)
			++counts[count];
		else
			++counts[abs(count) + 1001];
	}
	int count = 0;
	for (int i = 0; i < 2002; ++i)
		if (counts[i] != 0)
			++count;
	printf("%d", count);
}