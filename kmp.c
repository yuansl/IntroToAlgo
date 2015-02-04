/* KMP string-match algorithm */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int *compute_prefix_func(const char *pattern, int m)
{
	int *pi = malloc(m * sizeof(int));
	int i, q = -1;

	pi[0] = q;
	for (i = 1; i < m; i++) {
		while (q >= 0 && pi[q + 1] != pi[i])
			q = pi[q];
		if (pi[q + 1] == pi[i])
			q++;
		pi[i] = q;
	}
	return pi;
}

void kmp(const char *text, const char *pattern)
{
	int m = strlen(pattern);
	int n = strlen(text);
	int *pi = compute_prefix_func(pattern, m);
	int i, q;

	q = pi[0];
	for (i = 0; i < n; i++) {
		while (q >= 0 && pattern[q + 1] != text[i]) {
			q = pi[q];
		}

		if (pattern[q + 1] == text[i])
			q++;

		if (q == m - 1) {
			printf("pattern occurs with shift %d\n", i - m + 1);
			q = pi[q];
		}
	}
	free(pi);
}
