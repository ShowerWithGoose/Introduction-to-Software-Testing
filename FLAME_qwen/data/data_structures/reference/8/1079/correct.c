#include <stdio.h>
int graph[105][105], visited[105], queue[105];
int n, l, a, b;

void DFSsearch(int a[][105], int k) {
	int i = 0;
	printf("%d ", k);
	visited[k] = 1;

	for (i = 0; i < n; i++) {

		if (graph[i][k] && !visited[i]) {
			DFSsearch(a, i);
		}
	}
}

void BFSsearch(int a[][105], int k) {
	int front = 0, rear = 0;
	queue[rear++] = k;
	int i, temp;

	while (front <= rear) {
		temp = queue[front++];

		if (!visited[temp]) {
			visited[temp] = 1;
			printf("%d ", temp);

			for (i = 0; i < n; i++) {

				if (graph[i][temp] && !visited[i]) {
					queue[rear++] = i;
				}
			}
		}
	}
}

int main() {
	scanf("%d%d", &n, &l);

	for (int i = 0; i < l; i++) {

		scanf("%d%d", &a, &b);
		graph[a][b] = 1;
		graph[b][a] = 1;
	}

	DFSsearch(graph, 0);
	printf("\n");

	for (int i = 0; i < n; i++) {

		visited[i] = 0;
	}

	BFSsearch(graph, 0);
	printf("\n");

	for (int i = 0; i < n; i++) {

		visited[i] = 0;
	}

	scanf("%d", &a);
	visited[a] = 1;

	for (int i = 0; i < n; i++) {

		queue[i] = 0;
	}

	DFSsearch(graph, 0);
	printf("\n");

	for (int i = 0; i < n; i++) {

		visited[i] = 0;
	}

	visited[a] = 1;
	BFSsearch(graph, 0);
	printf("\n");
	return 0;
}

