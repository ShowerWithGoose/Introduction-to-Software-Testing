#include<stdio.h>
#define N  10002
int n, m, cnt = 1;
int a1[N], b1[N], a2[N], b2[N];
int m, rt = 1, nex[N], pre[N], a[N], s[N];
void ins(int x, int y) {
	int pos = rt;
	while(s[nex[pos]] > y && nex[pos]) pos = nex[pos];
	int to = nex[pos];
	if(s[to] == y && to) { a[to] += x; return ; }
	a[++ cnt] = x, s[cnt] = y;
	pre[cnt] = pos, nex[cnt] = to;
	nex[pos] = cnt, pre[to] = cnt;
}
int main() {
	while(1) {
		++ n, scanf("%d%d", &a1[n], &b1[n]);
		char c = getchar();
		if(c == '\n') break;
	}
	while(1) {
		++ m, scanf("%d%d", &a2[m], &b2[m]);
		char c = getchar();
		if(c == '\n') break;
	}
	int i, j;
	for(i = 1; i <= n; ++ i)
		for(j = 1; j <= m; ++ j)
			ins(a1[i] * a2[j], b1[i] + b2[j]);
	int pos = nex[rt];
	while(pos) printf("%d %d ", a[pos], s[pos]), pos = nex[pos];
	return 0;
}

