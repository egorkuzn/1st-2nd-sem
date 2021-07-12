#include <stdio.h>
#pragma warning (disable: 4996)
int main() {
	int a, b;
	scanf("%d%d", &a, &b);
	if ((a > b) && (a > 0) && (b >= 0)) {
		printf("legal");
	}
	else {
		printf("out of bounds");
	}
	return 0;
}