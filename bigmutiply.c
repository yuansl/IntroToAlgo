#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXSIZE 1000000

static char num[MAXSIZE];

void mutiply(int m, int n)
{
	int i, j, m0, n0, s, s0, c, c0, sign;

	memset(num, 0, sizeof(num));

	sign = 1;
	if (m < 0)
		sign *= -1;
	if (n < 0)
		sign *= -1;

	m = abs(m);
	n = abs(n);
	for (i = 0; n != 0; n /= 10, i++) {
		n0 = n % 10;
		c0 = 0;
		c = 0;
		for (j = i, m0 = m; m0 != 0; m0 /= 10, j++) {
			s = n0 * (m0 % 10) + c;
			s0 = num[j] + s % 10 + c0;
			num[j] = s0 % 10;
			c0 = s0 / 10;
			c = s / 10;
		}
		num[j] = c + c0;
	}

	if (sign < 0)
		putchar('-');

	for (j = MAXSIZE - 1; num[j] == 0; j--)
		continue;
	for (; j >= 0; j--)
		putchar(num[j] + '0');
	putchar('\n');
}

/* test-case */
int main(void)
{
	int m, n, i;

	i = 0;
	while (i++ < 1000000) {
		m = rand() % 10000;
		n = rand() % 10000;
		printf("m * n = %d ", m * n);
		mutiply(m, n);
	}
	return 0;
}
