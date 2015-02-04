#include <math.h>     /* for pow */

void radix_sort(int a[], int l, int r, int digit)
{
	int i, j, v, d = 0;

	for (d = 0; d < digit; d++)
		for (i = l; i < r; i++) {
			j = i + 1;
			v = a[j];
			while (j > l && 
			       a[j-1] / (int) pow(10, d) % 10 >
			       v / (int) pow(10, d) % 10) {
				a[j] = a[j - 1];
				j--;
			}
			a[j] = v;
		}
}
