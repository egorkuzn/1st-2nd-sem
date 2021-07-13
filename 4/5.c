#include <stdio.h>
#include <malloc.h>
#pragma warning (disable:4996)
void swap(int* a, int* b) {
	int c = *a;
	*a = *b;
	*b = c;
}
void shake_sort(int a[], int n) {
	int left = 1, right = n - 1, i;
	while (left <= right) {
		for (i = right; i >= left; --i)
			if (a[i - 1] > a[i])
				swap(&a[i - 1], &a[i]);
		++left;
		for (i = left; i <= right; ++i)
			if (a[i - 1] > a[i])
				swap(&a[i - 1], &a[i]);
		--right;
	}
}
int main() {
	int N;
	scanf("%d", &N);
	static int arr[100000];
	for (int i = 0; i < N; ++i)
		scanf("%d", &arr[i]);
	shake_sort(arr, N);
	for (int i = 0; i < N; ++i)
		printf("%d ", arr[i]);
	return 0;
}