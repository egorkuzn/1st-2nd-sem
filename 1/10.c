#include <stdio.h>
#pragma warning (disable: 4996)
int main() {
	int a, i = 1, count = 0;
	scanf("%d", &a);
	while (i + count < a) {
		count += i;
		++i;
	}
	if ((a - count) == 1)
		printf("1");
	else
		printf("0");
	return 0;
}