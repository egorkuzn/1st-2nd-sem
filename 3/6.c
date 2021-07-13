#include <stdio.h>
#include <malloc.h>

#pragma warning(disable: 4996);

void main()
{
	int N;
	scanf_s("%d", &N);
	int* arr = (int*)malloc(N * sizeof(int));
	int max = -10001, L, R;
	for (int i = 0; i < N; i++)
	{
		scanf_s("%d", &arr[i]);
		if (i < 1)
		{
			max = arr[i];
			L = i;
			R = i;
		}
	}
	int sr;
	for (int i = 0; i < N - 1; i++)
	{
		sr = arr[i];
		for (int j = i + 1; j < N; j++)
		{
			if (arr[i] > max)
			{
				max = arr[i];
				L = i;
				R = i;
			}
			sr = sr + arr[j];
			if (sr > max)
			{
				max = sr;
				L = i;
				R = j;

			}
		}
	}
	printf("%d %d %d", L, R, max);
}