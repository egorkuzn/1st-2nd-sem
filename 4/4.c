#include <stdio.h>
#pragma warning(disable:4996)
void swap(int* aa, int* b) {
	int c = *aa;
	*aa = *b;
	*b = c;
}
int main() {
	int N, a[100000];
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
		scanf("%d", &a[i]);
	int min = N - 1;
	for (int i = 0; i < N; ++i) {
		int min = N - 1;
		for (int j = i; j < N; ++j)
			if (a[j] < a[min])
				min = j;
		swap(&a[i], &a[min]);
	}
	for (int i = 0; i < N; ++i)
		printf("%d ", a[i]);
	return 0;
}