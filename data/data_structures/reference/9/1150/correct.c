#include<stdio.h>
int fx[1002], fy[1002], tx[1002], ty[1002];
int fa[1002], s[1002];
int n;
int is(int x, int y) {
	if(fx[x] == tx[y] && fy[x] == ty[y]) return 1;
	if(fx[y] == tx[x] && fy[y] == ty[x]) return 1;
	return 0;
}
int find(int x) {
	if(x == fa[x]) return fa[x];
	return fa[x] = find(fa[x]);
}
int main() {
	int i, j;
	scanf("%d", &n);
	for(i = 1; i <= n; ++ i)
		scanf("%d%d%d%d", &fx[i], &fy[i], &tx[i], &ty[i]);
	for(i = 1; i <= n; ++ i) fa[i] = i;
	for(i = 1; i <= n; ++ i)
		for(j = i + 1; j <= n; ++ j)
			if(is(i, j)) fa[find(j)] = fa[find(i)];
	for(i = 1; i <= n; ++ i) s[find(fa[i])] ++;
	int pos = 0, mx = 0, mi = 2147483647, p = 0;
	for(i = 1; i <= n; ++ i)
		if(s[i] > mx) mx = s[i], pos = i;
	for(i = 1; i <= n; ++ i)
		if(fa[i] == pos && fx[i] < mi) mi = fx[i], p = i;
	printf("%d %d %d", mx, fx[p], fy[p]);
}

