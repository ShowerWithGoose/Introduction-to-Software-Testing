#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <limits.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define M 100007
#define ll long long
char s[M],ch[M];
int main() {
	int i=0,head=0,flag;
	int lench,lens;
	gets(s);
	int len=strlen(s);
	if(s[0]=='0') {
		flag=1;
		for(i=0; i<len; i++) {
			if(s[i]=='.') {
				lens=len-2;
			} else if(s[i]=='0') {
				head++;
			} else {
				break;
			}
		}
		strcpy(ch,s+head+1);
		lench=strlen(ch);
		if(flag==1) {
			if(lench==1) {
				printf("%c%se-%d",ch[0],ch+1,head);
			} else {
				printf("%c.%se-%d",ch[0],ch+1,head);
			}
		}
	} 
	else {
		while(s[i++]!='.'){
			lens++;
		}
		printf("%c.",s[0]);
		strcpy(ch,s+1);	
		lench=strlen(ch);
		for(i=0;i<lench;i++){
			if(ch[i]=='.'){
				continue;
			}
			printf("%c",ch[i]);
		}
		printf("e%d",lens-1);
	}

	return 0;
}



