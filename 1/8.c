#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#pragma warning(disable: 4996);
void main()
{
	int desc;
	int a, b, c;
	scanf_s("%d%d%d", &a, &b, &c);
	if (a == 0) {
		if (b == 0 && c == 0) {
			printf("MANY");
		}
		else {
			if (b == 0 && c != 0) {
				printf("ERROR");
			}
			else {
				if (b != 0 && c != 0) {
					printf("%d\n%0.5lf", 1, (-c / (float)b));
				}
				else {
					if (b != 0 && c == 0) {
						printf("%d\n%0.5f", 1, 0);
					}
				}
			}
		}
	}

	if (abs(a) > 0)
		if ((b == 0 && c != 0) || ((abs(b) > 0) && (abs(c) > 0)))
		{
			desc = b * b - (4 * a * c);

			if (desc < 0)
				printf("NO");
			else {
				if (desc == 0 && b != 0)
				{
					double x = ((double)-b) / (2 * a);
					printf("1\n%0.5lf", x);
				}
				else {
					if (desc > 0)
					{
						double xx1 = ((double)-b - sqrt(desc)) / (2 * a);
						double xx2 = ((double)-b + sqrt(desc)) / (2 * a);
						double min = min(xx1, xx2);
						double max = max(xx1, xx2);
						printf("2\n%0.5lf %0.5lf", min, max);
					}
				}
			}
		}
		else {
			if ((abs(b) > 0) && c == 0)
			{
				double xx1 = 0;
				double xx2 = ((double)-b / a);
				double min = min(xx1, xx2);
				double max = max(xx1, xx2);
				printf("2\n%0.5lf %0.5lf", min, max);
			}
			else {
				if ((b + c) == 0 && (c * b) == 0) {
					printf("1\n%0.5f", 0);
				}
			}
		}

}