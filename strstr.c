#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *compute_prefix_func(const char *pattern, int m)
{
	int *pi = (int *) malloc(m * sizeof(int));
	int i, q;

	q = -1;
	pi[0] = q;
 	for (i = 1; i < m; i++) {
		while (q >= 0 && pattern[q + 1] != pattern[i])
			q = pi[q];
		if (pattern[q + 1] == pattern[i])
			q++;
		pi[i] = q;
	}

	return pi;
}

/* A substr implementation with KMP algorithm */
const char *m_substr(const char *dst, const char *pattern)
{
	if (pattern == NULL)
		return dst;

	int n = strlen(dst);
	int m = strlen(pattern);
	int *pi = compute_prefix_func(pattern, m);
	int i, q;

	q = pi[0];
	for (i = 0; i < n; i++) {
		while (q >= 0 && pattern[q+1] != dst[i])
			q = pi[q];
		if (pattern[q+1] == dst[i])
			q++;
		if (q == m - 1) {
			return dst + (i - m + 1);
		}
	}
	return NULL;
}

int main(void)
{
	char text[BUFSIZ], pattern[BUFSIZ];
	const char *substr;

	printf("text:");
	fgets(text, BUFSIZ, stdin);
	if (text[strlen(text) - 1] == '\n')
		text[strlen(text) - 1] = '\0';
	printf("patttern:");
	fgets(pattern, BUFSIZ, stdin);
	if (pattern[strlen(pattern) - 1] == '\n')
		pattern[strlen(pattern) - 1] = '\0';
	substr = m_substr(text, pattern);
	if (substr != NULL)
		printf("sub string: %s\n", substr);
	return 0;
}
