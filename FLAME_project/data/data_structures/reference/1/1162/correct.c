#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<math.h> 
#define int long long
int read() {
	int w = 0, t = 0; char ch = getchar();
	while(ch < '0' || ch > '9') t |= (ch == '-'), ch = getchar();
	while(ch >= '0' && ch <= '9') w = w * 10 + (ch - '0'), ch = getchar();
	return t ? -w : w;
}
int a[1111], pos[1111], n;
void DFS(int x) {
	if(x == n + 1) {
		int j;
		for(j = 1; j <= n; j++) {
			printf("%d ", a[j]);
		} printf("\n");
		return;
	}
	int i;
	for(i = 1; i <= n; i++) {
		if(pos[i]) continue;
		a[x] = i; pos[i] = 1; DFS(x + 1);
		pos[i] = 0;
	}
}
signed main() {
	n = read();
	DFS(1);
	return 0;
}


