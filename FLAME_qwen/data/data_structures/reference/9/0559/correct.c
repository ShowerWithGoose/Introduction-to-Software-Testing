#define eps 1e-11
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>
#include<ctype.h>
struct line {
	int x1;
	int y1;
	int x2;
	int y2;
};
struct line a[105];
int start[2] = {0};
int hash[105] = {0};
int cnt = 1, ans = 0, temp = 0;
int *p;

void dfs(struct line *a, int n, int ii) {
	
	int i = ii, j;
	for (j = 0; j < n; j++) {
		if (i == j) continue;
		if (a[i].x2 == a[j].x1 && a[i].y2 == a[j].y1) {
			if (hash[i] == 0) {
				cnt++;
				i = j;
				dfs(a, n, i);
			}
			hash[i] = 1;
			cnt--;
			temp++;
			
			if (cnt == 1 && cnt + temp > ans) {
				ans = cnt + temp;
				start[0] = a[*p].x1;
				start[1] = a[*p].y1;
				cnt = 1;
				temp = 0;
				memset(hash, 0, sizeof(hash));
			}
		}
	}
	return;
}
int main() {
	int n;
	scanf("%d", &n);

	char c;
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d%d%c", &a[i].x1, &a[i].y1, &a[i].x2, &a[i].y2, &c);
		if (c == '\n') continue;
	}
	for (int i = 0; i < n; i++) {
		p=&i;
		cnt = 1;
		temp = 0;
		memset(hash, 0, sizeof(hash));
		dfs(a, n, i);
	}
	printf("%d %d %d\n", ans, start[0], start[1]);
	return 0;
}


