#include<stdio.h>
#include<string.h>
int main(){
	char s[100];
	gets(s);
	int n=0,i,len=strlen(s);
	if(s[0]=='0'){
		i=2;
		while(s[i]=='0'){
			i++;
			n++;
		}
		if(i<len-1) printf("%c.",s[i]);
		else printf("%c",s[i]);
		for(i=i+1;i<len;i++){
			printf("%c",s[i]);
		}
		printf("e-%d",n+1);
	}
	else if(s[1]=='.'){
		printf("%se0",s);
	}
	else{
		printf("%c.",s[0]);
		for(i=1;s[i]!='.';i++){
			printf("%c",s[i]);
			n++;
		}
		for(i=i+1;i<len;i++){
			printf("%c",s[i]);
		}
		printf("e%d",n);
	}
	return 0;
}

