#include <math.h>
#include <stdio.h>

#pragma warning(disable:4996)
void main() {
	int n, iks, levo = 0, pravo = 0, seredina = 0, i = 0;
	static int a[1000001];
	scanf("%d %d", &n, &iks);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	pravo = n;
	do {
		seredina = (levo + pravo) / 2;
		if (a[seredina] < iks) {
			levo = seredina + 1;
		}
		else if (a[seredina] > iks) {
			pravo = seredina - 1;
		}
		++i;
	} 	while (a[seredina] != iks && i != (int)log2(n) + 1);
	if (a[seredina] != iks)
		printf("%d", -1);
	else
		printf("%d", seredina);
}