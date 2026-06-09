#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int read() {
	int w = 0, t = 0; char ch = getchar();
	while(ch < '0' || ch > '9') t |= (ch == '-'), ch = getchar();
	while(ch >= '0' && ch <= '9') w = w * 10 + (ch - '0'), ch = getchar();
	return t ? -w : w;
}
#define maxn 10005
int head, tail, vis[maxn], que[maxn], d[1111][1111], i, n, m, q, rt;
void DFS(int x) {
	int i; vis[x] = 1; printf("%d ", x);
	for(i = 1; i <= n; i++) {
		if(!vis[i] && d[x][i]) DFS(i);
	}
}
signed main() {
	n = read(); m = read();
	for(i = 1; i <= m; i++) {
		int x = read(), y = read(); 
		d[x][y] = 1; d[y][x] = 1;
	}
	DFS(0); for(i = 0; i <= n; i++) vis[i] = 0; printf("\n");
	que[1] = 0; head = tail = 1;
	while(head <= tail) {
		int x = que[head]; vis[x] = 1; printf("%d ", x);
		for(i = 1; i <= n; i++) {
			if(!vis[i] && d[x][i]) vis[i] = 1, que[++tail] = i;
		}
		head++;
	}
	for(i = 0; i <= n; i++) vis[i] = 0; printf("\n");
	rt = read(); vis[rt] = 1; DFS(0); 
	for(i = 0; i <= n; i++) vis[i] = 0; printf("\n");
	vis[rt] = 1; que[1] = 0; head = tail = 1;
	while(head <= tail) {
		int x = que[head]; vis[x] = 1; printf("%d ", x);
		for(i = 1; i <= n; i++) {
			if(!vis[i] && d[x][i]) vis[i] = 1, que[++tail] = i;
		}
		head++;
	}
}




