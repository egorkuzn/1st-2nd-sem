#include <stdio.h>
#pragma warning(disable: 4996)
int main() {
	int a,res=0,aa;
	scanf("%d",&aa);
	for (int i = 1; i <= aa; ++i) {
		scanf("%d", &a);
		if (a % 2 == 0) {
			res += a;
		}
	}
	printf("%d", res);
	return 0;
}
