#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define N 25
#define exchange(x, y) { int tmp = x; x = y; y = tmp; }

int partition(int a[], int l, int r)
{
	int i, j;

	i = l - 1;
	for (j = l; j < r; j++) {
		if (a[j] <= a[r]) {
			i++;
			if (i != j)
				exchange(a[i], a[j]);
		}
	}
	exchange(a[i+1], a[r]);
	return i + 1;
}

int partition2(int a[], int p, int r)
{
	int i, j, v;

	v = a[p];
	for (i = p, j = p + 1; j <= r; j++) {
		if (a[j] >= v) {
			i++;
			if (i != j)
				exchange(a[i], a[j]);
		}
	}
	exchange(a[i], a[p]);
	return i;
}

void quick_sort(int a[], int l, int r)
{
	if (l < r) {
		int m = partition(a, l, r);
		quick_sort(a, l, m - 1);
		quick_sort(a, m + 1, r);
	}
}
