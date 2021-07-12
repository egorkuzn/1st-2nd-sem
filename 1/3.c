#include <stdio.h>
#include <math.h>
#pragma warning(disable: 4996);
int main() {
	short a, b, c;
	scanf("%hi\n%hi\n%hi", &a, &b, &c);
	if (a > b) { a = b; }
	if (a > c) { a = c; }
	printf("%hi", a);
	return 0;
}