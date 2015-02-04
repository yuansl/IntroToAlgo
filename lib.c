#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <time.h>

double min_atof(const char *nptr)
{
	double retf = 0.0;
	int sign = 1;

	if (nptr == NULL)
		return 0;

	while (isspace(*nptr))
		nptr++;
	if (*nptr == '+')
		nptr++;
	if (*nptr == '-') {
		sign *= -1;
		nptr++;
	}
	while (isdigit(*nptr))
		retf = 10 * retf + *nptr++ - '0';
	if (*nptr == '.') {
		nptr++;
		int i = 1;
		while (isdigit(*nptr)) {
			retf += (*nptr++ - '0') / pow(10, i);
			i++;
		}
	}

	return retf * sign;
}

int min_atoi(const char *nptr)
{
	int ret = 0, sign = 1;

	if (nptr == NULL)
		return 0;

	while (isspace(*nptr))
		nptr++;

	if (*nptr == '+')
		nptr++;
	if (*nptr == '-') {
		sign *= -1;
		nptr++;
	}

	while (isdigit(*nptr))
		ret = 10 * ret + *nptr++ - '0';
	return ret * sign;

}

long min_atol(const char *nptr)
{
	long ret = 0;
	int sign = 1;

	if (nptr == NULL)
		return 0;

	while (isspace(*nptr))
		nptr++;
	if (*nptr == '+')
		nptr++;
	if (*nptr == '-') {
		sign *= -1;
		nptr++;
	}

	while (isdigit(*nptr))
		ret = 10 * ret + *nptr++ - '0';
	return ret * sign;
}

/* convert ascii string pointed to by nptr to double */
double min_strtod(const char *nptr, char **ept)
{
	double retf = 0.0;
	int sign = 1;

	if (nptr == NULL)
		return 0;

	while (isspace(*nptr))
		nptr++;
	if (*nptr == '+')
		nptr++;
	if (*nptr == '-') {
		nptr++;
		sign *= -1;
	}
	while (isdigit(*nptr))
		retf = retf * 10 + *nptr++ - '0';
	if (*nptr == '.') {
		nptr++;
		int i = 1;
		while (isdigit(*nptr)) {
			retf += (*nptr++ - '0') / pow(10, i);
			i++;
		}
	}
	if (ept != NULL)
		*ept = nptr;
	return retf * sign;
}

float min_strtof(const char *nptr, char **ept)
{
	float retf = 0.0;
	int sign = 1;

	if (nptr == NULL)
		return 0;

	while (isspace(*nptr))
		nptr++;
	if (*nptr == '+')
		nptr++;
	if (*nptr == '-') {
		nptr++;
		sign *= -1;
	}
	while (isdigit(*nptr))
		retf = retf * 10 + *nptr++ - '0';
	if (*nptr == '.') {
		nptr++;
		int i = 1;
		while (isdigit(*nptr)) {
			retf += (*nptr++ - '0') / pow(10, i);
			i++;
		}
	}

	if (ept != NULL)
		*ept = nptr;
	return retf * sign;
}

long double min_strtold(const char *nptr, char **ept)
{
	double ld = 0.0;
	int sign = 1;

	if (nptr == NULL)
		return 0;

	while (isspace(*nptr))
		nptr++;
	if (*nptr == '+')
		nptr++;
	if (*nptr == '-') {
		nptr++;
		sign *= -1;
	}
	while (isdigit(*nptr))
		ld = 10 * ld + *nptr++ - '0';
	if (*nptr == '.') {
		nptr++;
		int i = 1;
		while (isdigit(*nptr)) {
			ld += (*nptr++ - '0') / pow(10, i);
			i++;
		}
	}

	if (ept != NULL)
		*ept = nptr;
	return ld * sign;
}

long min_strtol(const char *nptr, char **ept, int base)
{
	long ret = 0.0;
	int sign = 1;

	if (nptr == NULL)
		return 0;

	while (isspace(*nptr))
		nptr++;
	if (*nptr == '+')
		nptr++;
	if (*nptr == '-') {
		nptr++;
		sign *= -1;
	}
	while (isdigit(*nptr))
		ret = ret * base + *nptr++ - '0';
	if (ept != NULL)
		*ept = nptr;
	return ret * sign;
}

long long min_strtoll(const char *nptr, char **ept, int base)
{
	long long ret = 0.0;
	int sign = 1;

	if (nptr == NULL)
		return 0;

	while (isspace(*nptr))
		nptr++;
	if (*nptr == '+')
		nptr++;
	if (*nptr == '-') {
		nptr++;
		sign *= -1;
	}
	while (isdigit(*nptr))
		ret = ret * base + *nptr++ - '0';
	if (ept != NULL)
		*ept = nptr;
	return ret * sign;
}

unsigned long min_strtoul(const char *nptr, char **ept, int base)
{
	unsigned long ret = 0.0;
	int sign = 1;

	if (nptr == NULL)
		return 0;

	while (isspace(*nptr))
		nptr++;
	if (*nptr == '+')
		nptr++;
	if (*nptr == '-') {
		nptr++;
		sign *= -1;
	}
	while (isdigit(*nptr))
		ret = ret * base + *nptr++ - '0';

	if (ept != NULL)
		*ept = nptr;
	return ret * sign;
}

unsigned long next = 1;

int min_rand(void)
{
	next = next * 1103515245 + 12345;
	return (next / 65536) % 32768;
}

void min_srand(unsigned int seed)
{
	next = seed;
}

char *m_strcpy(char to[], const char *from)
{
	int i;

	i = 0;
	while ((to[i] = from[i]) != '\0')
		i++;
	return to;
}

char *m_strncpy(char to[], const char *from, size_t n)
{
	int i;

	i = 0;
	while (i < n && (to[i] = from[i]) != '\0')
		i++;
	for (; i < n; i++)
		to[i] = '\0';
	return to;
}

char *m_strcat(char to[], const char *from)
{
	int i = strlen(to);
	while ((to[i] = from[i]) != '\0')
		i++;
	return to;
}

char *m_strncat(char *to, const char *from, size_t n)
{
	size_t offset = strlen(to);
	int i = 0;

	while (i < n && (to[offset+i] = from[i]) != '\0')
		i++;
	return to;
}

int main(int argc, char *argv[])
{
	int i;

	min_srand((unsigned int) time(NULL));

	for (i = 0; i < 10; i++) 
		printf("rand = %d, RAN_MAX = %d\n", min_rand(), RAND_MAX);
	return 0;
}
