#include <stdio.h>
struct line{
	int x1;
	int y1;
	int x2;
	int y2;
	int num;
}line[102];
void remov(int m, int n) {
	for (int i = m + 1; i <= n; i++) {
		line[i - 1] = line[i];
	}
	return;
}
int judge(int i, int m) {
	if (line[i].x1 == line[m].x2 && line[i].y1 == line[m].y2) return 1;
	if (line[i].x2 == line[m].x1 && line[i].y2 == line[m].y1) return 2;
	return 0;
}
void dfs(int m, int* k) {
	int color = 0;
	for (int i = m - 1; 0 <= i; i--) {
		if (judge(i, m) == 1) {
			color = 1;
			line[i].x1 = line[m].x1;
			line[i].y1 = line[m].y1;
			line[i].num = line[i].num + line[m].num;
			remov(m, *k);
			*k = *k - 1;
			dfs(i, k);
		}
		else if (judge(i, m) == 2) {
			color = 1;
			line[i].x2 = line[m].x2;
			line[i].y2 = line[m].y2;
			line[i].num = line[i].num + line[m].num;
			remov(m, *k);
			*k = *k - 1;
			dfs(i, k);
		}
	}
	if (color == 0) return;
}
int main() {
	int n;
	scanf("%d", &n);
	int k = 0;
	int MaxN = 0;
	int sx, sy;
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d%d", &line[k].x1, &line[k].y1, &line[k].x2, &line[k].y2);
		line[k].num = 1;
		dfs(k, &k);
		k++;
	}
	for (int i = 0; i < k; i++) {
		if (MaxN < line[i].num) {
			MaxN = line[i].num;
			sx = line[i].x1;
			sy = line[i].y1;
		}
	}
	printf("%d %d %d\n", MaxN, sx, sy);
	return 0;
}



