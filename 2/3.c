#include <stdio.h>
#pragma warning(disable: 4996)
int main() {
	int a;
	scanf("%d",&a);
	if (a == 1) {
		printf("NO");
		return 0;
	}
	for(int i=2; i<=sqrt(a); ++i)
		if ((a % i == 0)&&(a>i)) {
			printf("NO");
			return 0;
		}
	printf("YES");
	return 0;
}
