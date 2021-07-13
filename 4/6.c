#include <stdio.h>
#pragma warning(disable:4996)
int invtab_to_permut(int a[], int b[], int n) {
	for (int i = 0; i < n; ++i)
		if (a[n - 1 - i] > i)
			return 0;
	b[0] = n;
	for (int i = n - 1; i > 0; --i) {
		int k = 0;
		while (a[i - 1] > 0) {
			--a[i - 1];
			++k;
		}
		if (b[k] > 0) {
			if (b[n - 1] > 0)
				return 0;
			for (int j = n - 1; j > k; --j)
				b[j] = b[j - 1];
		}
		b[k] = i;
	}

	return 1;
}

int main() {
	int N, a[1000], b[1000];
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		scanf("%d", &a[i]);
		b[i] = 0;
	}
	if (invtab_to_permut(a, b, N))
		for (int i = 0; i < N; ++i)
			printf("%d ", b[i]);
	else
		printf("NO");

	return 0;
}