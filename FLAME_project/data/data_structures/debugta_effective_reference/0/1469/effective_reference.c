#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>
#include<limits.h>
#define min(b,a) ((b<=a)?b:a)
#define max(b,a) ((b>=a)?b:a)
int type(char x) {
	if(isdigit(x)) return 1;
	if(islower(x)) return 2;
	if(isupper(x)) return 3;
}
int main() {
	char b,a;
	scanf("%c",&b);
	while(~scanf("%c",&a)) {
		printf("%c",b);
		if(a!='-') {
			b=a;
		} else {
			char c;
			scanf("%c",&c);
			if(type(b)==type(c)&&b<c) {
				for(int j=b+1; j<=c-1; j++) {
					printf("%c",j);
				}
			}
			else{
				printf("-");
			}
			b=c;
		}
	}
	printf("%c",b);
	return 0;
}


