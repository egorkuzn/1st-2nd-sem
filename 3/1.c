#include <stdio.h>
#pragma warning(disable:4996)
int main() {
	int b[100];
	int N;
	scanf("%d", &N);
	for (short i = 0; i < N; ++i)
		scanf("%d", &b[i]);
	for (short j = 0; j < N; ++j) {
		int count = 0;
		for (short i = j; i < N; ++i)
			if (b[j] > b[i])
				++count;
		printf("%d ", count);
	}
	return 0;
}