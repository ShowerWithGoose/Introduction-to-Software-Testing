#include <stdio.h>
#include <string.h>
#include <ctype.h>

char suanshi[1000],s[1000];
int tp;
int get() {
	int x = 0, c = s[tp];
	while (!isdigit(c)) c = s[++tp];
	while (isdigit(c)) x = x * 10 + c - '0', c = s[++tp];
	return x;
}

int main() {
	gets(suanshi);
	int i=0,i1=0,he;



	while(suanshi[i]!='=') {
		if(suanshi[i]!=' ') {
			s[i1]=suanshi[i];
			i1++;

		}
		i++;
	}
	s[i1] = '=';
	i=0;
	i1=0;
	int ans = 0, nw = 0;
	nw = get();
	while (1) {
		char c = s[tp];
		if (c == '+') ans += nw, nw = get();
		else if (c == '-') ans += nw, nw = -get();
		else if (c == '*') nw *= get();
		else if (c == '/') nw /= get();
		else if (c == '=') return printf("%d", ans + nw), 0;
	}



	return 0;
}

// 0

