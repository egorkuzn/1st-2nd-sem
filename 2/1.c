#include <stdio.h>
#pragma warning(disable: 4996)
int main() {
	int a,res=0;
	scanf("%d",&a);
	for (int i = 1; i <= a; ++i)
		res += i;
	printf("%d", res);
	return 0;
}