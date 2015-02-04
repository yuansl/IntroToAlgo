#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define V 9

int graph[V + 1][V + 1];
int D[V + 1][V + 1];
static FILE *fp;

void Dijkstra(int s)
{
	int i, j, min, visit[V];

	for (i = 1; i <= V; i++)
		visit[i] = 0;

	visit[s] = 1;
	for (i = 1; i <= V; i++)
		if (graph[s][i] != INT_MAX)
			D[s][i] = graph[s][i];
		else
			D[s][i] = INT_MAX;

	for (;;) {
		min = s;
		for (j = 1; j <= V; j++)
			if (!visit[j] && D[s][j] < D[s][min])
				min = j;
		if (min == s)
			break;
		visit[min] = 1;
		for (j = 1; j <= V; j++)
			if (!visit[j] && graph[min][j] != INT_MAX && 
			    graph[min][j]+ D[s][min] < D[s][j])
				D[s][j] = D[s][min] + graph[min][j];
	}
	D[s][s] = 0;
}

void read_graph(void)
{
	int u, v, w;

	for (u = 1; u <= V; u++)
		for (v = 1; v <= V; v++)
			graph[u][v] = INT_MAX;

	while (fscanf(fp, "%d%d%d", &u, &v, &w) != EOF)
		graph[u][v] = w;
}

int main(void)
{
	int i, s;
	fp = fopen("input", "r");

	read_graph();
	while (scanf("%d", &s) != EOF) {
		Dijkstra(s);
		for (i = 1; i <= V; i++)
			if (D[s][i] == INT_MAX)
				printf(" INFINITE");
			else
				printf(" %d", D[s][i]);
		printf("\n");
	}
	fclose(fp);
	return 0;
}
