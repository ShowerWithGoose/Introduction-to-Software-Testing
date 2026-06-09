#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int a[105][105];
int find[105];
int n, m;

void dfs(int i) {
	printf("%d ", i);
	find[i] = 1;

	for (int j = 0; j < n; j++) {

		if (a[i][j] == 1 && find[j] == 0) {
			dfs(j);
		}
	}
}

void DFS() {
	for (int i = 0; i < n; i++) {

		if (find[i] == 0)
			dfs(i);
	}
}
int queue[105];
int rear = -1, head, cnt;

void pushq(int x) {
	if (cnt < 105) {
		rear = (rear + 1) % 105;
		queue[rear] = x;
		cnt++;
	}
}

int popq() {
	int x;

	if (cnt > 0) {
		x = queue[head];
		head = (head + 1) % 105;
		cnt--;
	}

	return x;
}

void BFS() {
	int x;

	for (int i = 0; i < n; i++) {

		if (find[i] == 0) {
			pushq(i);
			find[i] = 1;
		}

		while (cnt != 0) {
			x = popq();
			printf("%d ", x);

			for (int k = 0; k < n; k++) {

				if (find[k] == 0 && a[x][k] == 1) {
					pushq(k);
					find[k] = 1;
				}
			}
		}
	}
}

int main() {
	int x, y, del;

	for (int i = 0; i < 105; i++) {

		for (int j = 0; j < 105; j++)

			a[i][j] = -1;
	}

	scanf("%d", &n);
	scanf("%d", &m);

	for (int i = 0; i < m; i++) {

		scanf("%d", &x);
		scanf("%d", &y);
		a[x][y] = 1;
		a[y][x] = 1;
	}

	DFS();
	printf("\n");

	for (int i = 0; i < 105; i++)

		find[i] = 0;
	BFS();
	printf("\n");
	scanf("%d", &del);

	for (int i = 0; i < n; i++) {

		for (int j = 0; j < n; j++) {

			if (i == del || j == del)
				a[i][j] = -1;
		}
	}

	for (int i = 0; i < 105; i++)

		find[i] = 0;
	find[del] = 1;
	DFS();
	printf("\n");

	for (int i = 0; i < 105; i++)

		find[i] = 0;
	find[del] = 1;
	BFS();
	printf("\n");
	return 0;
}
