#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

#define SIZE 10

struct result {
	int low;
	int high;
	int sum;
};

struct result find_maximum_crossing_subarray(int a[], int l, int m, int h)
{
	int left_sum, right_sum, left_i, right_i, sum, i;
	struct result res;

	sum = 0;
	left_sum = INT_MIN;
	for (i = m; i >= l; i--) {
		sum += a[i];
		if (sum > left_sum) {
			left_sum = sum;
			left_i = i;
		}
	}
	sum = 0;
	right_sum = INT_MIN;
	for (i = m + 1; i <= h; i++) {
		sum += a[i];
		if (sum > right_sum) {
			right_sum = sum;
			right_i = i;
		}
	}
	res.low = left_i;
	res.high = right_i;
	res.sum = left_sum + right_sum;
	return res;
}

struct result find_maximum_subarray(int a[], int l, int r)
{
	if (r < l) {
		struct result res;
		res.low = -1;
		res.high = -1;
		res.sum = 0;
		return res;
	} else if (l == r) {
		struct result res;
		res.low = l;
		res.high = r;
		res.sum = a[l];
		return res;
	} else {
		int m;
		struct result left, right, cross;

		m = (l + r) / 2;
		left = find_maximum_subarray(a, l, m);
		right = find_maximum_subarray(a, m + 1, r);
		cross = find_maximum_crossing_subarray(a, l, m, r);
		if (left.sum >= right.sum && left.sum >= cross.sum)
			return left;
		else if (right.sum >= left.sum && right.sum >= cross.sum)
			return right;
		else
			return cross;
	}
}
