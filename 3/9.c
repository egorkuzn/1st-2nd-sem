#include <stdlib.h>
#include <math.h>
#include <stdio.h>

#pragma warning(disable:4996)

void main() {
	int n, iks, levo = 0, pravo = 0, sered = 0, i = 0;
	static float a[1000001];
	scanf("%d %d", &n, &iks);
	for (int i = 0; i < n; ++i) {
		scanf("%f", &a[i]);
	}
	pravo = n;
	do {
		sered = (levo + pravo) / 2;
		if (a[sered] < iks) {
			levo = sered;
		}
		else if (a[sered] > iks) {
			pravo = sered;
		}
		++i;
	} while (a[sered] != iks && i != (int)log2(n) + 1);
	if (sered == n - 1) {
		sered -= 1;
	}
	if (fabsf(iks - a[sered]) > fabsf(iks - a[sered + 1]))
		printf("%d", sered + 1);
	else
		printf("%d", sered);
}