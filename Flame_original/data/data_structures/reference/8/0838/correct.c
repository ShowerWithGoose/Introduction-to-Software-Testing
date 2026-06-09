#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int pic[105][200], que[105];
int m, n;
int ss[105] = {0};
void DFS(int x) ;
void BFS(int x) ;

int main() {
	int x, y, a;
	scanf("%d %d", &m, &n);
	memset(que, 0, sizeof(que));
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &x, &y);
		pic[x][y] = pic[y][x] = 1;
	}
	scanf("%d", &a);
	memset(ss, 0, sizeof(ss));
	DFS(0);
	printf("\n");
	memset(ss, 0, sizeof(ss));
	BFS(0);
	printf("\n");
	memset(ss, 0, sizeof(ss));
	ss[a] = 1;
	DFS(0);
	memset(ss, 0, sizeof(ss));
	printf("\n");
	ss[a] = 1;
	BFS(0);
	printf("\n");
	return 0;
}

void DFS(int x) {
	printf("%d ", x);
	ss[x] = 1;
	for (int i = 0; i < m; i++)
		if (pic[x][i] != 0 && ss[i] != 1) {
			DFS(i);
		}
}

void BFS(int x) {
	int i, head = 0, tail = 1, tmp;
	que[head] = x;
	while (head <= tail) {
		tmp = que[head];
		head++;
		if (ss[tmp] == 0) {
			printf("%d ", tmp);
			ss[tmp] = 1;
			for (i = 0; i < m; i++)
				if (pic[tmp][i] != 0 && ss[i] != 1)
					que[tail++] = i;		//未访问过且为1则入队
		} else {
			continue;
		}
	}
}

