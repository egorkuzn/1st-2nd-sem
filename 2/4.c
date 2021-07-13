#include <stdio.h>
#pragma warning(disable: 4996)
int main() {
	int b;
	scanf("%d", &b);
	if (b >= 2) {
		printf("2 ");
		for (int a = 3; a <= b; a += 2) {
			if ((a % 10 == 5)&&(a>10)) {
				continue;
			}
			short c = 0;
			for (int i = 2; i <= sqrt(a); ++i)
				if ((a % i == 0) && (a > i))
				{
					++c;
					break;
				}
			if(c==0)
				printf("%d ", a);
		}
	}
	return 0;
}
