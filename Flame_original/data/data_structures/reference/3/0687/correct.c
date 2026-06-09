#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define pi 3.1415926535
#define re register
#define eps 1e-15
#define ArrayNum(x) (sizeof(x)/sizeof(x[0]))
int main() {
	char s[100];
	char *p=NULL;
	int i,l;
	scanf("%s",s);
	p=strchr(s,'.');
	if(p==NULL) {
		puts(s);
	} else if(p-s==1) {
		if(s[0]=='0') {
			for(i=2; i<strlen(s); i++) {
				if(s[i]!='0') {
					l=i;
					break;
				}
			}
			if(l==strlen(s)-1) {
				printf("%c",s[l]);
				for(i=l+1; s[i]!='\0'; i++) {
					printf("%c",s[i]);
				}
				printf("e-%d",l-1);
			} else {
				printf("%c",s[l]);
				printf(".");
				for(i=l+1; s[i]!='\0'; i++) {
					printf("%c",s[i]);
				}
				printf("e-%d",l-1);
			}
		} else {
			for(i=0; i<strlen(s); i++) {
				printf("%c",s[i]);
			}
			printf("e0");
		}
	} else {
		l=p-s;
		printf("%c",s[0]);
		printf(".");
		for(i=0; i<strlen(s)-1; i++) {
			if(s[i+1]!='.') printf("%c",s[i+1]);
		}
		//printf("%c",s[strlen(s)-1]);
		printf("e%d",l-1);
	}
	return 0;
}


