#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char s[110],a[110];
int main(){
	int i,j,k,num=0,len;
	gets(s);
	len=strlen(s);
	if(s[0]=='0'&&s[1]=='.'){
		i=2;
		while(s[i]=='0'){
			num++;
			i++;
		}
		printf("%c",s[i]);
		if(s[i+1]!='\0'){
			printf(".");
		}
		for(j=i+1;j<len;j++){
			printf("%c",s[j]);
		}
		printf("e-%d",num+1);
	}
	else if(s[0]>'0'&&(s[1]=='.'||s[1]=='\0')){
		printf("%se0",s);
	}
	else{
		for(i=0;s[i]!='.';i++){
			a[i]=s[i];
		}
		num=strlen(a)-1;
		printf("%c.",s[0]);
		for(i=1;i<len;i++){
			if(s[i]=='.'){
				continue;
			}
			printf("%c",s[i]);
		}
		printf("e%d",num);
	}
	return 0;
}



