#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define LEFT(i) (i<<1)
#define RIGHT(i) ((i<<1) + 1)
#define PARENT(i) (i>>1)
#define exchange(x, y) { int tmp = x; x = y; y = tmp; }
#define MAXSIZE 25


static int heapsize = 0;

void max_heapify(int heap[], int k)
{
	int max, l, r;

	l = LEFT(k);
	r = RIGHT(k);
	if (l <= heapsize && heap[l] > heap[k])
		max = l;
	else
		max = k;
	if (r <= heapsize && heap[r] > heap[max])
		max = r;
	if (max != k) {
		exchange(heap[k], heap[max]);
		max_heapify(heap, max);
	}
}

void build_max_heap(int heap[])
{
	int j;
	for (j = heapsize / 2; j >= 1; j--)
		max_heapify(heap, j);
}

int maximum_heap(int heap[])
{
	return heap[1];
}

void del_maximum_heap(int heap[])
{
	heap[1] = heap[heapsize];
	heapsize--;
	max_heapify(heap, 1);
}

void heap_sort(int heap[])
{
	build_max_heap(heap);
	while (heapsize > 1) {
		exchange(heap[1], heap[heapsize]);
		heapsize--;
		max_heapify(heap, 1);
	}
}
