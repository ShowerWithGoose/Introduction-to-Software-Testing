#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
#define LL long long
char s[11111];
int main() {
	int i=0,n=0;
	gets(s);
	n=strlen(s);
	for(i; i<11111; i++) {
		if(s[i]!='-') {
			printf("%c",s[i]);
		} else {
			char c=s[i-1];
			if((48<=s[i-1]&&s[i+1]<=57&&s[i-1]<s[i+1])||(s[i-1]>=65&&s[i+1]<=90&&s[i-1]<s[i+1])||(s[i-1]>=97&&s[i+1]<=122&&s[i-1]<s[i+1])) {
				while(c!=s[i+1]) {
					c+=1;
					printf("%c",c);
				}
				if(c==s[i+1]) i+=1;
			} else printf("-");
		}
	}
	return 0;
}




