#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 25

void merge(int a[], int left, int mid, int right)
{
	int n = right - left + 1;
	int i, l, r, b[n];

	memset(b, 0, sizeof(b));

	l = left;
	r = mid + 1;
	i = 0;
	while (l <= mid && r <= right)
		if (a[l] < a[r])
			b[i++] = a[l++];
		else
			b[i++] = a[r++];
	while (l <= mid)
		b[i++] = a[l++];
	while (r <= right)
		b[i++] = a[r++];
	while (right >= left)
		a[right--] = b[--i];
}

void merge_sort(int a[], int l, int r)
{
	if (l < r) {
		int mid = (l + r) / 2;
		merge_sort(a, l, mid);
		merge_sort(a, mid + 1, r);
		merge(a, l, mid, r);
	}
}
