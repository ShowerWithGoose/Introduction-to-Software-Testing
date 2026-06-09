#include<stdio.h>
#define N 10005
int ch[N][26], s[N];
int len, cnt = 1, t;
char a[N], q[N];
void ins(int o, int dt) {
	if(dt == len) { s[o] ++; return ; }
	if(!ch[o][a[dt + 1] - 'a'])
		ch[o][a[dt + 1] - 'a'] = ++ cnt;
	ins(ch[o][a[dt + 1] - 'a'], dt + 1);
}
int is(char x) {
	if(x >= 'a' && x <= 'z') return 1;
	if(x >= 'A' && x <= 'Z') return 1;
	return 0;
}
char low(char x) {
	if(x >= 'A' && x <= 'Z') return x - 'A' + 'a';
	return x;
}
void prin(int o, int dt) {
	if(!o) return ;
	int i;
	if(s[o]) {
		for(i = 1; i <= t; ++ i)
			printf("%c", q[i]);
		printf(" %d\n", s[o]);
	}
	for(i = 0; i < 26; ++ i) {
		q[++ t] = i + 'a';
		prin(ch[o][i], dt + 1);
		-- t;
	}
}
int main() {
	freopen("article.txt", "r", stdin);
	char x;
	while((x = getchar()) != EOF) {
		len = 0;
		while(!is(x) && (x = getchar()) != EOF);
		if(x == EOF) break;
		while(is(x)) {
			a[++ len] = low(x);
			x = getchar();
		}
		if(len) ins(1, 0);
	}
	prin(1, 0);
	fclose(stdin);
	return 0;
}

