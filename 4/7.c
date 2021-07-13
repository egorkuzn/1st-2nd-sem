#include <stdio.h>
#include <math.h>
#pragma warning(disable:4996)
void swap(int* a, int* b)
{
	int c = *a;
	*a = *b;
	*b = c;
}
void next_permut(int array[], int length) {
	int pick = 1;
	for (int k = 0; k < length - 1; ++k)
		if (array[k] < array[k + 1]) {
			pick = 0;
			break;
		}
	if (pick) {
		for (int k = 0; k < length; ++k)
			array[k] = k + 1;
		return;
	}
	int i = length - 1;
	while (i > 0 && array[i - 1] >= array[i])
		i--;
	int j = length - 1;
	while (array[j] <= array[i - 1])
		j--;
	int temp = array[i - 1];
	array[i - 1] = array[j];
	array[j] = temp;

	j = length - 1;
	while (i < j) {
		temp = array[i];
		array[i] = array[j];
		array[j] = temp;
		i++;
		j--;
	}
}
int main() {
	int N, arr[1000];
	scanf("%d", &N);
	if (N == 1) {
		scanf("%d", &N);
		printf("1");
		return 0;
	}
	for (int i = 0; i < N; ++i)
		scanf("%d", &arr[i]);
	for (int k = 0; k < 1; ++k) {
		next_permut(arr, N);
		for (int i = 0; i < N; ++i)
			printf("%d ", arr[i]);
	}
	return 0;
}