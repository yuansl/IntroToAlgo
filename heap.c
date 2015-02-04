#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <ctype.h>
#include <time.h>

#define MAXN 20
#define swap(x, y) { int tmp = x; x = y; y = tmp; }

static char *heap;
static int N;

void heap_init(int maxn)
{
	heap = (char *) malloc(sizeof(char) * (maxn + 1));
	N = 0;
}

void heap_fix_up(char heap[], int k)
{
	while (k > 1 && heap[k] > heap[k / 2]) {
		swap(heap[k], heap[k / 2]);
		k /= 2;
	}
}

void heap_fix_down(char heap[], int k, int N)
{
	int j;

	while (2 * k <= N) {
		j = 2 * k;
		if (j < N && (heap[j] < heap[j + 1]))
			j++;
		if (!(heap[k] < heap[j]))
			break;
		swap(heap[k], heap[j]);
		k = j;
	}
}

void output_heap(char heap[], int k)
{
	while (k >= 1)
		printf(" %c", heap[k--]);
	printf("\n");
}

void heap_insert(char item)
{
	heap[++N] = item;
	heap_fix_up(heap, N);
}

char heap_del_max(void)
{
	swap(heap[N], heap[1]);
	heap_fix_down(heap, 1, N - 1);
	return heap[N--];
}

char heap_replace_max(char item)
{
	swap(item, heap[1]);
	heap_fix_down(heap, 1, N);
	return heap[1];
}

void heap_sort(char array[], int l, int r)
{
	int k;

	for (k = l; k <= r; k++)
		heap_insert(array[k]);
	for (k = r; k >= l; k--)
		array[k] = heap_del_max();
}
