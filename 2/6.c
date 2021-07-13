#include <stdio.h>
#pragma warning(disable: 4996)
int main() {
	int b,a=0,aa=0,c=0;
	scanf("%d", &b);
	for (int i = 0; i < b; ++i) {
		int bb;
		scanf("%d", &bb);
		if (bb == 0) {
			++a;
		}
		else {
			if (bb > 0) {
				++aa;
			}
			else {
				++c;
			}
		}
	}
	double p;
	p = (double)c / b;
	printf("%0.5lf ",p);
	p = (double)a/ b;
	printf("%0.5lf ", p);
	p = (double)aa / b;
	printf("%0.5lf", p);
	return 0;
}
