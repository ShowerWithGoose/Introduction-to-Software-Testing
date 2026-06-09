#include<stdio.h>
#include<string.h>
#include<math.h>
char s[10000];
int main(){
	gets(s);
	int i,j;
	if(s[0]=='0'){
		for(i=0;s[i]=='0'||s[i]=='.';i++){
		}
		printf("%c",s[i]);
		if(i+1<strlen(s))
		printf(".");
		for(j=i+1;j<strlen(s);j++)
		printf("%c",s[j]);
		printf("e-%d",i-1);
	}
	else{
		printf("%c.",s[0]);
		for(i=1;i<strlen(s);i++){
			if(s[i]!='.')
			printf("%c",s[i]);
			else
			j=i;
		}
		printf("e%d",j-1);
	}
	return 0;
} 

