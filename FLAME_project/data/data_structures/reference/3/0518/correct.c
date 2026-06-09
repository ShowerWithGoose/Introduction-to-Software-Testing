#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<time.h>
#define eps 1e-10
char s[100];
int b[10000];
int i,j,x,flag,len;
int main() {
	gets(s);
	int l=strlen(s);
	for(i=0; i<l; i++) {
		if(s[i]=='.') {
			len=i;
			if(s[0]=='0'&&len==1)
				flag=1;
		} else {
			b[j++]=s[i]-'0';
		}
	}
	j--;
	if(len==0) {
		printf("%d",b[0]);
		for(i=1; i<=j; i++)
			if(s[i]>0) x=1;
		if(x) {
			printf(".");
			for(i=1; i<=j; i++)
				printf("%d",b[i]);
		}
		printf("e%d",l-1);
	} else {
		if(flag) {
			for(i=1; i<=j; i++)
				if(b[i]>0) break;
			x=i;
			printf("%d",b[i++]);
			if(i<=j)
				printf(".");
			for(i; i<=j; i++)
				printf("%d",b[i]);
			printf("e-%d",x);
		} else {
			printf("%d.",b[0]);
			for(i=1; i<=j; i++)
				printf("%d",b[i]);
			printf("e%d",len-1);
		}
	}
	return 0;
}

