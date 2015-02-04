#include <stdio.h>

void bubble_sort(int a[], int l, int r)
{
	int pass, j, n;

	n = r - l + 1;
	for (pass = 1; pass <= n - 1; pass++)
		for (j = 0; j < n - 1; j++)
			if (a[j] > a[j + 1])
				exchange(a[j], a[j + 1]);
}
