#include <stdio.h>
#include <string.h>
#include <math.h>

char s[1000010];

int main() {
	scanf("%s",s);
	int i,j;
	for(i=0;i<strlen(s);i++) {
		if(s[i]!='-') {
			printf("%c",s[i]);
			continue;
		}
		if(i==0) {
			printf("%c",s[i]);
			continue;
		}
		if(i==strlen(s)-1) {
			printf("%c",s[i]);
			continue;
		}
		int flag=0;
		char c;
		if(s[i-1]<='Z' && s[i-1]>='A' && s[i+1]<='Z' && s[i+1]>='A' && s[i-1]<s[i+1]) {
			flag=1;
			for(c=s[i-1]+1;c<s[i+1];c++) {
				printf("%c",c);
			}
		}
		if(s[i-1]<='z' && s[i-1]>='a' && s[i+1]<='z' && s[i+1]>='a' && s[i-1]<s[i+1]) {
			flag=1;
			for(c=s[i-1]+1;c<s[i+1];c++) {
				printf("%c",c);
			}
		}
		if(s[i-1]<='9' && s[i-1]>='0' && s[i+1]<='9' && s[i+1]>='0' && s[i-1]<s[i+1]) {
			flag=1;
			for(c=s[i-1]+1;c<s[i+1];c++) {
				printf("%c",c);
			}
		}
		if(!flag) printf("%c",s[i]);
	}
	return 0;
}

