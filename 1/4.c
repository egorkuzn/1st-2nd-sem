#include <stdio.h>
#include <math.h>
#pragma warning (disable: 4996)
void main()
{
	int a1, b1;
	scanf_s("%d%d", &a1, &b1);
	int e1 = a1 % b1;
	int c1 = floor(a1 / (double)b1);
	int d1 = ceil(a1 / (double)b1);
	if (0 <= a1) {
		printf("%d %d %d %d", c1, d1, c1, e1);
	}
	else
	{
		printf("%d %d %d ", c1, d1, d1);
		if (abs(a1 % b1) > 0) {
			e1 = (a1 % b1) + b1;
		}
		else {
			e1 = 0;
		}
		printf("%d", e1);
	}
}