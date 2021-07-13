#include <stdio.h>
#pragma warning(disable: 4996)
int main() {
	int a,kmax=1,kmin=1,max=-10001,min=10001, hr;
	scanf("%d", &a);
	for (int i = 0; i < a; ++i) {
		scanf("%d", &hr);
		if (hr > max) { max=hr;
		kmax = i + 1;
		}
		if (hr < min) {
			min=hr;
			kmin = i + 1;
		}
	}
	printf("%d %d %d %d", min, kmin, max, kmax);
	return 0;
}
