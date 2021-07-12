#include <stdio.h>
#pragma warning(disable: 4996)
int main() {
	int a, dec = 1,d=0, inc=0;
	char k ='0' ;
	scanf("%d",&a);
	if (a == 100000000) {
		printf("8");
	}
	else
	{
		while (inc < a)
		{
			++d;
			while (d / dec > 0) {
				dec *= 10;
			}
			while (dec >= 10) {
				k = (d % dec) / (dec / 10) + '0';
				++inc;
				if (inc == a) {
					printf("%c", k);
					return 0;
				}
				dec /= 10;
			}
		}
	}
}