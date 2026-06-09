#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
#define LL long long
char s[1111];
int main() {
	int i=0,n=0,m=0;
	char c;
	gets(s);
	int l=strlen(s);
	for(; i<l; i++) {
		if(s[i]=='0')
			continue;
		if(s[i]!='0'&&s[i]!='.') {
			if(n!=0)
				continue;
			n=i+1;
			if (s[0] == '0')
				n = i - 1;
		}
		if(s[i]=='.')
			m=i-1;
	}
	int ss=n;
	ss=i+m+n;
	if(s[0]=='0') {
		if(n+2>=l-1)
			printf("%c", s[n+ 1]);
		else
			printf("%c.", s[n+ 1]);
		for ( i = n + 2; i <= l - 1; i++) {
			printf("%c", s[i]);
		}
		printf("e-%d", abs(n - m));
	}
	if(s[0]!='0') {
			printf("%c.", s[n-1]);
		for ( i = n; i <=l-1; i++) {
			if(s[i]=='.')
			continue;
			printf("%c", s[i]);
		}
		printf("e%d", abs(n - m-1));
	}
	return 0;
}




