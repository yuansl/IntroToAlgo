#include <stdio.h>
#include <string.h>

/* original string-match algorithm */
void strmatch(const char *text, const char *pattern)
{
	int i, n, m, q;

	n = strlen(text);
	m = strlen(pattern);
	q = 0;
	for (i = 0; i <= n - m; i++) {
		while (text[i + q] == pattern[q]) {
			q++;
			if (q == m) {
				printf("pattern occurs with shift %d\n", i);
				break;
			}
		}
		q = 0;
	}
}
int main(void)
{
	char text[BUFSIZ], pattern[BUFSIZ];

	printf("text: ");
	fgets(text, BUFSIZ, stdin);
	if (text[strlen(text) - 1] == '\n')
		text[strlen(text) - 1] = '\0';
	printf("pattern: ");
	scanf("%s", pattern);
	strmatch(text, pattern);
	return 0;
}
