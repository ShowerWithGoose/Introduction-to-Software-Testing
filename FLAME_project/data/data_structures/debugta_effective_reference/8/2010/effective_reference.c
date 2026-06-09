#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>

void init(int m);
void dfs(int v);
void bfs(int v);

int m, n;
int graph[100][100];
int visited[100], que[200];

int main()
{
	int v1, v2, v;
	fscanf(stdin, "%d%d", &m, &n);
	init(m);
	for (int i = 0; i < n; i++) {
		fscanf(stdin, "%d%d", &v1, &v2);
		graph[v1][v2] = 1;
		graph[v2][v1] = 1;
	}
	fscanf(stdin, "%d", &v);
	dfs(0);
	fprintf(stdout, "\n");
	memset(visited, 0, sizeof(visited));
	bfs(0); fprintf(stdout, "\n");
	memset(visited, 0, sizeof(visited));
	visited[v] = 1;
	dfs(0);
	fprintf(stdout, "\n");
	memset(visited, 0, sizeof(visited));
	visited[v] = 1;
	bfs(0);
	printf("\n");
	return 0;
}

void init(int m)
{
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			graph[i][j] = -1;
		}
		visited[i] = -1;
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			graph[i][j] = 0;
		}
		visited[i] = 0;
	}
	return;
}

void dfs(int v)
{
	fprintf(stdout, "%d ", v);
	visited[v] = 1;
	for (int i = 0; i < m; i++) {
		if (graph[v][i] && !visited[i]) {
			dfs(i);
		}
	}
	return;
}

void bfs(int v)
{
	int head = 0, tail = 1, tmp;
	que[head] = v;
	while (head <= tail) {
		tmp = que[head];
		head++;
		if (visited[tmp]) {
			continue;
		}
		else {
			fprintf(stdout, "%d ", tmp);
			visited[tmp] = 1;
			for (int i = 0; i < m; i++) {
				if (graph[tmp][i] != 0 && visited[i] == 0) {
					que[tail++] = i;
				}
			}
		}
	}
	return;
}
