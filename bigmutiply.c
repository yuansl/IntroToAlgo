#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#define MAXSIZE 1000
#define swap(x, y) \
	do { int tmp = x; x = y; y = tmp; } while (0)

static char num[MAXSIZE];

char *mutiply(int m, int n)
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

	for (j = MAXSIZE - 1; j >= 0; j--)
		num[j] += '0';

	for (j = MAXSIZE - 1; j >= 0 && num[j] == '0'; j--)
		num[j] = '\0';
	if (j < 0) {
		num[++j] = '0';
		return num;
	}
	
	for (i = 0; i < j; i++, j--)
		swap(num[i], num[j]);
	return num;
}

/* test-case */
int main(void)
{
	int m, n, i;
	char *ret;

	srand(time(NULL));
	i = 0;
	while (i++ < 10) {
		m = rand() % 100000000;
		n = rand() % 100000000;
		ret = mutiply(m, n);
		printf("%d * %d = %s\n", m, n, ret);
	}

	return 0;
}
