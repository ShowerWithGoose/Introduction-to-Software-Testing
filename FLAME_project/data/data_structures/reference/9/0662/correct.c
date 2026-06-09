#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int n, f[1000], Max, mx, my, cnt;
struct node{
	int x, y, xx, yy;
}q[1000];
int cmp(const void *a, const void *b) {
	struct node *c = (struct node *)a;
	struct node *d = (struct node *)b;
	return (c->x > d->x) ? 1 : -1;
}
void dfs(int k) {
	f[k] = 1; cnt ++;
	int i;
	for (i = k+1; i <= n; i++) {
		if (q[i].x == q[k].xx && q[i].y == q[k].yy) {
			dfs(i);
			break;
		}
	}
}
int main() 
{
	int i, j;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) 
		scanf("%d%d%d%d", &q[i].x, &q[i].y, &q[i].xx, &q[i].yy);
	qsort(q+1, n, sizeof(q[0]), cmp);
	//for (i = 1; i <= n; i++) printf("%d %d %d %d\n", q[i].x, q[i].y, q[i].xx, q[i].yy);
	for (i = 1; i <= n; i++) 
		if (!f[i]) {
			cnt = 0;
			dfs(i);
			if (Max < cnt) Max = cnt, mx = q[i].x, my = q[i].y;
		}
	printf("%d %d %d\n", Max, mx, my);
	
	return 0;
}

