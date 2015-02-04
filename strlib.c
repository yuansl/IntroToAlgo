#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINE 100

char *m_strcpy(char to[], const char from[])
{
	int i = 0;
	while ((to[i] = from[i]) != '\0')
		i++;
	return to;
}

char *m_strncpy(char to[], const char from[], size_t n)
{
	int i = 0;
	while (i < n && (to[i]=from[i]) != '\0')
		i++;
	to[i] = '\0';
	return to;
}

char *m_strcat(char *to, const char *from)
{
	size_t off = strlen(to);
	int i = 0;

	while ((to[off+i] = from[i]) != '\0')
		i++;
	return to;
}

char *m_strncat(char *to, const char *from, size_t n)
{
	size_t off = strlen(to);
	int i = 0;

	while (i < n && (to[off + i] = from[i]) != '\0')
		i++;
	to[off + i] = '\0';
	return to;
}

int m_strcmp(const char *s1, const char *s2) 
{
	int i = 0;

	while (s1[i] != '\0' && s1[i] == s2[i])
		i++;
	return s1[i] - s2[i];
}

int m_strncmp(const char *s1, const char *s2, size_t n)
{
	int i = 0;
	while (i < n && s1[i] != '\0' && s1[i] == s2[i])
		i++;
	return s1[i] - s2[i];
}

char *m_strchr(const char *s, int c)
{
	while (*s != '\0') {
		if (*s == c)
			return s;
		s++;
	}
	return NULL;
}

size_t m_strcspn(const char *s1, const char *s2)
{
	size_t n = 0, this_n = 0;
	int not_in = true;

	while (*s1 != '\0') {
		if (strchr(s2, *s1) != NULL) {
			not_in = false;
			this_n = 0;
		} else {
			not_in = true;
			this_n++;
		}
		if (not_in == true && this_n > n)
			n = this_n;
		s1++;
	}
	return n;
}

int main(void)
{
	int *p = 0;
	printf("p = %p\n", p);
	int **pp = &p;
	*pp = malloc(sizeof(int));

	printf("p = %p\n", p);
	free(*pp);

	printf("strcspn = %ld\n", m_strcspn("abcdefg", "boy"));
	return 0;
}
