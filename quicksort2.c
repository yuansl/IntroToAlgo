#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 25
#define exchange(x, y) { int tmp = x; x = y; y = tmp; }

int partition(int a[], int l, int r)
{
	int i, j;

	i = l - 1;
	for (j = l; j < r; j++)
		if (a[j] <= a[r]) {
			i++;
			if (i != j) 
				exchange(a[i], a[j]);
		}
	exchange(a[i + 1], a[r]);
	return i + 1;
}

int random_partition(int a[], int l, int  r)
{
	int i = rand() % (r - l + 1) + l;
	exchange(a[r], a[i]);
	return partition(a, l, r);
}

void quicksort(int a[], int l, int r)
{
	if (l < r) {
		int m = random_partition(a, l, r);
		quicksort(a, l, m - 1);
		quicksort(a, m + 1, r);
	}
}

