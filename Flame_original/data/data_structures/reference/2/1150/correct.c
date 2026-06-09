#include<stdio.h>
#include<string.h> 
char s[100002];
int d[100002];
int main() {
	int ans = 0, a = 0, b = 0, x;
	char c;
	while(scanf("%d", &x) != EOF) {
		c = getchar();
		while(c == ' ') c = getchar();
		d[++ a] = x, s[++ b] = c;
	}
	int i, tmp = d[1], fl = 1;
	for(i = 1; i <= a; ++ i) {
		if(s[i] == '*') tmp *= d[i + 1];
		if(s[i] == '/') tmp /= d[i + 1];
		if(s[i] == '+') ans += tmp, tmp = d[i + 1];
		if(s[i] == '-') ans += tmp, tmp = -d[i + 1];
		if(s[i] == '=') ans += tmp;
	}
	printf("%d\n", ans);
}
/*
5 - 1 * 2 * 3 + 12 / 2 / 2  =

*/



