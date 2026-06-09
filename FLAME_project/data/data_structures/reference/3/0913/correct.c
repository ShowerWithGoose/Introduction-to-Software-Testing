#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


int main(){
	char s[110];
	gets(s);
	int lenth=strlen(s),m=0,n=0;
	if(s[0]=='0'){
		for(int i=2;i<lenth;i++){
			if(s[i]=='0'){
				m++;
			}
			else{
				n=lenth-m-2;
				break;
			}
		}
		if(n==1){
			printf("%ce-%d",s[lenth-1],m+1);
		}
		else{
			printf("%c.",s[m+2]);
			for(int i=m+3;i<=lenth-1;i++){
				printf("%c",s[i]);
			}
			printf("e-%d",m+1);
		}
	}
	else{
		for(int i=0;i<lenth;i++){
			if(s[i]=='.'){
				break;
			}
			else{
				m++;
			}
		}
		printf("%c.",s[0]);
		for(int i=1;i<=m-1;i++){
			printf("%c",s[i]);
		}
		for(int i=m+1;i<lenth;i++){
			printf("%c",s[i]);
		}
		printf("e%d",m-1);
	}
	
	return 0;
}


