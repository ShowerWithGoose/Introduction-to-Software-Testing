#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define maxn 10005
int read() {
	int w = 0, t = 0; char ch = getchar();
	while(ch < '0' || ch > '9') t |= (ch == '-'), ch = getchar();
	while(ch >= '0' && ch <= '9') w = w * 10 + (ch - '0'), ch = getchar();
	return t ? -w : w;
}
int n, a[maxn], cnt, rt, ls[maxn], rs[maxn];
int add(int now, int x) {
	if(!now) {now = ++cnt; a[now] = x; return now;}
	if(x < a[now]) ls[now] = add(ls[now], x);
	else rs[now] = add(rs[now], x);
	return now;
}
void DFS(int x, int dep) {
	if(!ls[x] && !rs[x]) {
		printf("%d %d\n", a[x], dep);
	}
	if(ls[x]) DFS(ls[x], dep + 1);
	if(rs[x]) DFS(rs[x], dep + 1);
}
int main() {
	//freopen("1.in", "r", stdin);
	n = read(); int i;
	for(i = 1; i <= n; i++) {
		int x = read(); rt = add(rt, x);
	}
	DFS(rt, 1);
}

