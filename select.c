#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 25
#define exchange(x, y) { int tmp = x; x = y; y = tmp; }

void select_sort(int a[], int l, int r)
{
	int i, j, min;

	for (i = l; i < r; i++) {
		min = i;
		for (j = i + 1; j <= r; j++)
			if (a[j] < a[min])
				min = j;
		exchange(a[i], a[min]);
	}
}
