/* Editor-distance problem */
#include <stdio.h>
#include <string.h>

#define min(a, b) (a < b ? a : b)

int f(const char *str1, int n, const char *str2, int m)
{
	return str1[n - 1] != str2[m - 1] ? 1 : 0;
}

int edit_distance(char *str1, int n, char *str2, int m)
{
	if (n == 0 && m == 0)
		return 0;
	else if (n == 0)
		return m;
	else if (m == 0)
		return n;
	else {
		int ret, x;
		ret = edit_distance(str1, n - 1, str2, m) + 1;
		x = edit_distance(str1, n, str2, m - 1) + 1;
		ret = min(ret, x);
		x = edit_distance(str1, n - 1, str2, m - 1)
			+ f(str1, n, str2, m);
		return ret = min(ret, x);
	}
}

int main(void)
{
	/* Test-case */
	char *p = "fcdffdfdfd";
	char *q = "fc";
	int ret = edit_distance(p, strlen(p), q, strlen(q));
	printf("ret = %d\n", ret);
	return 0;
}
