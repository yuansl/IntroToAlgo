int maximum_subarray(int a[], int l, int r)
{
	int maxsum, sum, i;

	maxsum = 0;
	sum = 0;
	for (i = l; i <= r; i++) {
		sum += a[i];
		if (sum > maxsum)
			maxsum = sum;
		else if (sum < 0)
			sum = 0;
	}
	return sum;
}
