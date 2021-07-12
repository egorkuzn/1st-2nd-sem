#include <stdio.h>
#include <math.h>
#pragma warning(disable: 4996);
int main() {
	int h, m, s, d;
	scanf("%d%d%d%d", &h, &m, &s, &d);
	s += d % 60;
	d /= 60;
	m += d % 60;
	d /= 60;
	h += d % 24;
	if (s >= 60) {
		s -= 60;
		++m;
	}
	if (m >= 60) {
		m -= 60;
		++h;
	}
	if (h >= 24) {
		h -= 24;
	}
	printf("%d %d %d", h, m, s);
	return 0;
}