#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define int long long
int read() {
	int w = 0, t = 0; char ch = getchar();
	while(ch < '0' || ch > '9') t |= (ch == '-'), ch = getchar();
	while(ch >= '0' && ch <= '9') w = w * 10 + (ch - '0'), ch = getchar();
	return t ? -w : w;
}
int st[1111], cnt = 0;
signed main() {
	while(1) {
		int op = read();
		if(op == -1) break;
		if(op == 1) {
			int x = read(); 
			if(cnt == 100) printf("error ");
			else st[++cnt] = x;
		}
		if(op == 0) {
			if(cnt == 0) printf("error ");
			else {
				printf("%d ", st[cnt]); cnt--;
			}
		}
	} 
}

