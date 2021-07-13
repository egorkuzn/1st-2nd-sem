#include <stdio.h>
#include <math.h>
#pragma warning (disable:4996)
long long gcd(long long  a, long long b) {
	return b ? gcd(b, a % b) : a;
}
long long f(long long a, long long b) {
	return a / gcd(a, b) * b;
}
int main() {
	int N;
	long long a, b;
	static long long mass[5000];
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		scanf("%lld%lld", &a, &b);
		if (a < b)
			mass[i] = f(a, b);
		else
			mass[i] = f(b, a);

	}
	printf("%lld", mass[0]);
	for (int i = 1; i < N; ++i)
		printf("\n%lld", mass[i]);
	return 0;
}