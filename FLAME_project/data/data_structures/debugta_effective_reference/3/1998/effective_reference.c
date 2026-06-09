#include<stdio.h>
#include<math.h>
#include<string.h>
int main(){
    char s[100];
	scanf("%s",s);
	int len = strlen(s);
	int dot,flag;
	int i,wa;
	for(i=0;s[i]=='0'||s[i]=='.';i++)	{
		if(s[i]=='.'){
			dot=i;
		}
	}
	for(wa=0;s[wa]!='.';wa++){
	}
	dot=wa;
	flag=i;
	printf("%c",s[i]);
	i++;
	if(flag==len-1){
		printf("e%d",dot-flag);
	}
	else{
		printf(".");
	for(;i<len;i++){
		if(s[i]!='.')
		printf("%c",s[i]);
	}
	if(dot<flag)
	printf("e%d",dot-flag);
	else
	printf("e%d",dot-flag-1);
}
	
	return 0;
}

