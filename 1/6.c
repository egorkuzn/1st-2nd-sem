#include <stdio.h>
#pragma warning(disable: 4996);
int main() {
	int x, y, z;
	scanf("%d%d%d", &x, &y, &z);
	if (x <= 0) {
		printf("-1");
		return 0;
	}
	if (y <= 0) {
		printf("-2");
		return 0;
	}
	if (z <= 0) {
		printf("-3");
		return 0;
	}
	long long S;
	S = 2 * ((x * y) + (x * z) + (z * y));
	printf("%lli", S);
	return 0;
}