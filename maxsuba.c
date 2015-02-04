#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#define N 10

static int low, high;

int find_maximum_subarray(int a[], int l, int r)
{
	int i, x, sum, maxsum;

	maxsum = INT_MIN;
	sum = 0;
	x = l;
	for (i = l; i <= r; i++) {
		sum += a[i];
		if (sum > maxsum) {
			maxsum = sum;
			low = x;
			high = i;
		}

		if (sum < 0) {
			sum = 0;
			x = i + 1;
		}
	}
	return maxsum;
}

int find_maximum_cross_subarray(int a[], int left, int mid, int right)
{
	int i, sum, left_sum, right_sum;

	sum = 0;
	left_sum = INT_MIN;
	for (i = mid; i >= left; i--) {
		sum += a[i];
		if (sum > left_sum)
			left_sum = sum;
	}

	sum = 0;
	right_sum = INT_MIN;
	for (i = mid + 1; i <= right; i++) {
		sum += a[i];
		if (sum > right_sum)
			right_sum = sum;
	}
	return left_sum + right_sum;
}

int find_maximum_subarray2(int a[], int l, int r)
{
	int mid, maxsum, left_sum, right_sum, cross_sum;

	if (l == r) {
		low = l;
		high = r;
		maxsum = a[l];
	} else {
		mid = (l + r) / 2;
		left_sum = find_maximum_subarray2(a, l, mid);
		right_sum = find_maximum_subarray2(a, mid + 1, r);
		cross_sum = find_maximum_cross_subarray(a, l, mid, r);
		if (left_sum >= right_sum && left_sum >= cross_sum)
			maxsum = left_sum;
		else if (right_sum >= left_sum && right_sum >= cross_sum)
			maxsum = right_sum;
		else
			maxsum = cross_sum;
	}
	return maxsum;
}
