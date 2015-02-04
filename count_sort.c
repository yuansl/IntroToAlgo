
/* count sort algorithm */
void count_sort(int a[], int l, int r)
{
	const int n = r - l + 1;
	int i, j, c[n + 1], b[n];

	for (i = 0; i < n; i++) {
		c[i] = 0;
		b[i] = 0;
	}
	c[i] = 0;
	for (i = l; i <= r; i++)
		c[a[i]] = c[a[i]] + 1;
	for (i = 1; i <= n; i++)
		c[i] += c[i - 1];
	for (i = r; i >= l; i--) {
		b[c[a[i]]] = a[i];
		c[a[i]]--;
	}
	for (i = l, j = 1; i <= r && j < n; i++, j++)
		a[i] = b[j];
}
