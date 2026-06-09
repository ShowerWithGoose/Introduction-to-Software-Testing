#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>
#include<limits.h>
#define min(a,b) ((a<=b)?a:b)
#define max(a,b) ((a>=b)?a:b)
int type(char x) {
	if(isdigit(x)) return 1;
	if(islower(x)) return 2;
	if(isupper(x)) return 3;
}
int main() {
	char a,b;
	scanf("%c",&a);
	while(~scanf("%c",&b)) {
		printf("%c",a);
		if(b!='-') {
			a=b;
		} else {
			char c;
			scanf("%c",&c);
			if(type(a)==type(c)&&a<c) {
				for(int i=a+1; i<=c-1; i++) {
					printf("%c",i);
				}
			}
			else{
				printf("-");
			}
			a=c;
		}
	}
	printf("%c",a);
	return 0;
}


