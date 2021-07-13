#include <stdio.h>
#pragma warning(disable:4996)
int main() {
	int N;
	scanf("%d", &N);
	int a[1001];
	int i;
	for (i = 1; i <= N; ++i)
		scanf("%d", &a[i]);
	for (i = 1; i <= N; ++i) {
		int count = 0;
		int flag = 0;
		for (int j = N; j > 0; --j) {
			if (a[j] == i)
				flag = 1;
			if (flag && a[j] > i)
				++count;
		}
		printf("%d ", count);
	}

	return 0;
}