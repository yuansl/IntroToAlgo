#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/* convert a long to string */
char *ltoa(long n)
{
	char ch, *buf;
	int i, j;


	buf = malloc(BUFSIZ * sizeof(char));
	i = 0;
	while (n > 0) {
		buf[i++] = n % 10 + '0';
		n /= 10;
	}
	buf[i] = '\0';
	for (j = i - 1, i = 0; i < j; i++, j--)
		ch = buf[i], buf[i] = buf[j], buf[j] = ch;
	return buf;
}

int main(void)
{
	char *str;
	long num;

	scanf("%ld", &num);
	str = ltoa(num);
	printf("str = %s\n", str);
	free(str);
	return 0;
}
