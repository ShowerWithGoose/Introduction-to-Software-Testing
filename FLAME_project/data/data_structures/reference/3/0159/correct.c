#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

char s[105];

int main() {
	int i,count=0;
	fgets(s,100,stdin);
	if(s[0]!='0') {
		printf("%c.",s[0]);
		for(i=1; s[i]!='.'; i++) {
			printf("%c",s[i]);
			count++;
		}
		for(++i; s[i]!='\n'; i++) {
			printf("%c",s[i]);
		}
		printf("e%d",count);
	} else {
		count++;
		for(i=2; s[i]=='0'; i++) {
			count++;
		}
		printf("%c",s[i]);
		if(s[++i]!='\n') {
			printf(".");
			for(; i<strlen(s)&&s[i]!='\n'; i++) {
				printf("%c",s[i]);
			}
		}

		printf("e-%d",count);
	}
	return 0;
}


