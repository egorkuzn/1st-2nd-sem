#include <stdio.h>
#pragma warning(disable: 4996);
int main() {
	int N, M, P, K, L, g;
	scanf("%d", &N);
	scanf("%d%d%d%d", &M, &P, &K, &L);
	g = M / (L * (P - 1) + (K - 1));
	K = 1; P = 1;
	while (N > (g * K + (P - 1) * L * g)) {
		if (K < L)
			++K;
		else {
			K = 1;
			++P;
		}
	}
	printf("%d %d", P, K);
	return 0;
}