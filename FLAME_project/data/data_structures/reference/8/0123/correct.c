#include <stdio.h>
#include <string.h>
int weight[1000][1000], visit[1000], que[1000];
int m, n;

void DFS(int a) {
	int i;
	printf("%d ", a);
	visit[a] = -1;
	for (i = 0; i < n; ++i) {
		if (weight[a][i] && !visit[i]) {
			DFS(i);
		}
	}
}

void BFS(int a) {
	int i, head = 0, tail = 1, tmp;
	que[head] = a;
	while (head <= tail) {
		tmp = que[head];
		++head;
		if (visit[tmp] == -1) {
			continue;
		} else {
			printf("%d ", tmp);
			visit[tmp] = -1;
			for (i = 0; i < n; ++i) {
				if (weight[tmp][i] && !visit[i]) {
					que[tail++] = i;
				}
			}
		}
	}
}

int main(void) {
	int a, b, i, delet;
	scanf("%d %d", &n, &m);
	for (i = 0; i < m; ++i) {
		scanf("%d %d", &a, &b);
		weight[a][b] = -1;
		weight[b][a] = -1;
	}
	DFS(0);
	printf("\n");
	memset(visit, 0, sizeof(visit));
	BFS(0);
	printf("\n");
	scanf("%d", &delet);
	memset(visit, 0, sizeof(visit));
	visit[delet] = -1;
	DFS(0);
	printf("\n");
	memset(visit, 0, sizeof(visit));
	memset(que, 0, sizeof(que));
	visit[delet] = -1;
	BFS(0);
	printf("\n");
	return 0;
}


