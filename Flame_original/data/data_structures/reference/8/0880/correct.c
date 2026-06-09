#include <stdio.h>

int a, b, linjie[100][100], temp[100], temp2[100], visit;
void Dfs(int p) {
	if (visit == 0) {
		printf("%d", p);
		visit = 1;
	} else {
		printf(" %d", p);
	}
	temp[p] = 1;
	for (int i = 1; i <= a; i++) {
		if (linjie[p][i] == 1 && temp[i] == 0) {
			Dfs(i);
		}
	}
}

void Bfs(int p) {
	int t;
	temp2[1] = p;
	for (int j = 1, r = 1; j <= r;) {
		t = temp2[j++];
		if (temp[t] == 1) {
			continue;
		}
		if (visit == 0) {
			printf("%d", t);
			visit = 1;
		} else {
			printf(" %d", t);
		}

		temp[t] = 1;
		for (int i = 1; i <= a; i++) {
			if (linjie[t][i] == 1 && temp[i] == 0) {
				temp2[++r] = i;
			}
		}
	}
}

int main() {
	int x, y;
	scanf("%d%d", &a, &b);
	for (int i = 1; i <= b; i++) {
		scanf("%d%d", &x, &y);
		linjie[x][y] = 1;
		linjie[y][x] = 1;
	}
	Dfs(0);
	printf("\n");
	for (int k = 0; k < 100; k++) {
		temp[k] = 0;
		visit = 0;
	}
	Bfs(0);
	printf("\n");
	for (int k = 0; k < 100; k++) {
		temp[k] = 0;
		visit = 0;
	}
	scanf("%d", &x);
	temp[x] = 1;
	Dfs(0);
	printf("\n");
	for (int k = 0; k < 100; k++) {
		temp[k] = 0;
		visit = 0;
	}
	temp[x] = 1;
	Bfs(0);
	printf("\n");
	for (int k = 0; k < 100; k++) {
		temp[k] = 0;
		visit = 0;
	}
}

