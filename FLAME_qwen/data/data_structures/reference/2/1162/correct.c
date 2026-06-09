#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<math.h> 
#define int long long
char s;
int n, ans = 0;
signed main() {
	int p = 1, w = 1, t = 1;
	while(1) { int x;
		scanf("%d", &x); s = getchar();
		while(s == ' ') s = getchar();
		if(s == '+' || s == '-' || s == '=') {
			//printf("%d\n", w);
			if(t == 1) w = w * x;
			else w = w / x;
			ans += p * w; t = 1; w = 1;
		}
		if(s == '+') p = 1; 
		if(s == '-') p = -1; 
		if(s == '=') break;
		if(s == '*' || s == '/')  {
			if(t == 1) w = w * x; 
			else w = w / x;
			if(s == '*') t = 1; else t = 2;
		}
		//printf("%d\n", w);
	}
	printf("%lld", ans);
	return 0;
}

