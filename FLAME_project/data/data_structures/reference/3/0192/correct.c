#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

#define LL  long long
#define ULL  unsigned long long

int main(void){
	char s[150];
	scanf("%s",s);
	int cnt=0,flag=0,l=strlen(s);
	if(s[0]=='0'){
		if(l==1){
			printf("0e0");
		}else{
			for(int i=2;i<l;i++){
				if(s[i]=='0'&&!flag){
					cnt++;
				}else{
					if(i+1<l&&!flag){
						printf("%c.",s[i]);
					}else{
						printf("%c",s[i]);
					}
					flag=1;
				}
			}
			printf("e-%d",cnt+1);
		}
	}else{
		printf("%c.",s[0]);
		for(int i=1;i<l;i++){
			if(s[i]!='.'&&!flag){
				cnt++;
				printf("%c",s[i]);
			}else if(s[i]=='.'){
				flag=1;
			}else{
				printf("%c",s[i]);
			}
		}
		printf("e%d",cnt);
	}
	return 0;
}

