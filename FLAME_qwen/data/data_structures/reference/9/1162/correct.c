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
int n, i, j, vis[111], nxt[111], sx[111], sy[111], tx[111], ty[111];
int ans, cnt, lst[111], xx, yy;
int main() {
	n = read(); 
	for(i = 1; i <= n; i++) {
		sx[i] = read(); sy[i] = read();
		tx[i] = read(); ty[i] = read();
	}	
	for(i = 1; i <= n; i++) {
		for(j = 1; j <= n; j++) {
			if(ty[i] == sy[j] && tx[i] == sx[j]) {
				nxt[i] = j; lst[j] = i;
			}
		}
	}
	for(i = 1; i <= n; i++) {
		//printf("%d %d\n", i, nxt[i]);
		if(!lst[i]) {
			int x = i, cnt = 0;
			while(x) {
				cnt++; x = nxt[x];
			}
			if(cnt > ans) {
			ans = cnt; xx = sx[i]; yy = sy[i];
			}
		}
		
	}
	printf("%d %d %d\n", ans, xx, yy);
	return 0;
}

