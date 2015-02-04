#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void countsort(int a[], int n, int maximum)
{
	int i, b[n], c[maximum+1];

	memset(c, 0, sizeof(c));
	for (i = 0; i < n; i++)
		c[a[i]]++;
	for (i = 1; i <= maximum; i++)
		c[i] += c[i-1];
	for (i = 0; i < n; i++) {
		c[a[i]]--;
		b[c[a[i]]] = a[i];
	}
	for (i = 0; i < n; i++)
		a[i] = b[i];
}
