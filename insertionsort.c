#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertionsort(int a[], int n)
{
	int i, j, v;

	for (i = 1; i < n; i++) {
		v = a[i];
		j = i - 1;
		while (j >= 0 && a[j] > v) {
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = v;
	}
}
