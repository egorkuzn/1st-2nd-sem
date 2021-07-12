#include <stdio.h>
#pragma warning(disable: 4996)
int main() {
	int b, count=0;
	scanf("%d", &b);
	while (b > 0) {
		count *= 10;
		count+=b % 10;
		b /= 10;
	}
	printf("%d",count);
	return 0;
}