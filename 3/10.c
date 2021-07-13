#include <math.h>

#include <stdlib.h>
#include <stdio.h>
#pragma warning(disable:4996);
int ghtn[12][2] = {
{31, 31},
{28, 29},
{31, 31},
{30, 30},
{31, 31},
{30, 30},
{31, 31},
{31, 31},
{30, 30},
{31, 31},
{30, 30},
{31, 31}
};

int rock(int hp) {
	return ((hp % 4 == 0 && hp % 100 != 0) || hp % 400 == 0);
}

void main() {
	int dot, ddt, momo, toto, elka, dubrava;
	scanf("%d%d%d%d%d%d", &dot, &momo, &elka, &ddt, &toto, &dubrava);

	int sumdot = 0, sumddt = 0;

	if (momo > 12 || momo < 1 || toto > 12 || toto < 1) {
		printf("%s", "ERROR");
		return;
	}
	else if (dot > ghtn[momo - 1][rock(elka)] || ddt > ghtn[toto - 1][rock(dubrava)] ||
		dot < 1 || ddt < 1 || elka > 2050 || elka < 1 || dubrava > 2050 || dubrava < 1) {
		printf("%s", "ERROR");
		return;
	}

	for (int i = 1; i < elka; ++i) {
		if (rock(i)) sumdot += 366;
		else sumdot += 365;
	}

	for (int i = 1; i < dubrava; ++i)
	{
		if (rock(i))sumddt += 366;
		else sumddt += 365;
	}

	for (int i = 1; i < momo; ++i)
	{
		sumdot += ghtn[i - 1][rock(elka)];
	}

	sumdot += dot;

	for (int i = 1; i < toto; ++i)
	{
		sumddt += ghtn[i - 1][rock(dubrava)];
	}

	sumddt += ddt;

	printf("%d", abs(sumddt - sumdot));
}