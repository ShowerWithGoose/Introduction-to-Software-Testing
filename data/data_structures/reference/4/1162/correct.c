#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define maxn 100005
int read() {
	int w = 0, t = 0; char ch = getchar();
	while(ch < '0' || ch > '9') t |= (ch == '-'), ch = getchar();
	while(ch >= '0' && ch <= '9') w = w * 10 + (ch - '0'), ch = getchar();
	return t ? -w : w;
}
char s[maxn];
int st[maxn], sum[maxn], cnt, cntx, rt = 1, ch[maxn][31], now;
int check(char c) {
	if(c >= 'a' && c <= 'z') return (c - 'a' + 1);
	if(c >= 'A' && c <= 'Z') return (c - 'A' + 1);
	return 0;
}
void DFS(int x) {
	int i, j;
	if(sum[x] && x != rt) {
		for(j = 1; j <= cntx; j++) {
			printf("%c", st[j] + 'a' - 1);
		}
		printf(" %d\n", sum[x]);
	}
	for(i = 1; i <= 26; i++) {
		if(ch[x][i]) {
			st[++cntx] = i;
			DFS(ch[x][i]); cntx--;
		}
	}
}
int main() {
	freopen("article.txt", "r", stdin);
	cnt = 1, now = rt;
	char x;
	while((x = getchar()) != EOF) { 
		now = rt;
		while(!check(x) && x != EOF) x = getchar();
		while(check(x)) s[++ cntx] = x, x = getchar();
		int i;
		for(i = 1; i <= cntx; i++) {
			int p = check(s[i]);
			if(ch[now][p]) now = ch[now][p];
			else ch[now][p] = ++cnt, now = ch[now][p];
		}
		sum[now]++; cntx = 0;
	}
	DFS(1);
}

