#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAX_N 10010

char s[MAX_N];
int main() {
	fgets(s,10010,stdin);
//	printf("%s",s);
	int i;
	int p=0,lst=0;
	for(i=0;i<strlen(s)-1;i++) {
		if(s[i]=='0') continue;
		if(s[i]!='0' && s[i]!='.') {
			if(lst!=0) continue;
			if(s[0]=='0') lst=i-1;
			else lst=i+1;
		}
		if(s[i]=='.') p=i-1;   
	}
	int len=lst-p;
//	printf("%d\n",len);
	if(s[0]!='0') {
		printf("%c.",s[lst-1]);
		for(i=lst;i<strlen(s)-1;i++) {
			if(s[i]=='.') continue;
			printf("%c",s[i]);
		}
		printf("e%d",abs(len-1));
	}                   
	else {
		if(lst+2 >= strlen(s)-1) printf("%c",s[lst+1]);
		else printf("%c.",s[lst+1]);
		for(i=lst+2;i<strlen(s)-1;i++) printf("%c",s[i]);
		printf("e-%d",abs(len));
	}
	return 0;
}

