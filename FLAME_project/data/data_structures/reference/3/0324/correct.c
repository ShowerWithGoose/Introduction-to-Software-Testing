#include<stdio.h>
#include<string.h>
int main(){
	char s[200];
	int i,j,k;
	int n;  int l=strlen(s);
	gets(s);
	if(s[0]=='0'){
		for(i=2;s[i]!='\0';i++){
			if(s[i]!='0'){
				printf("%c",s[i]);
				n=i-1;
				break;
			}
		}
		if(s[i+1]!='\0')
			printf(".");		
		for(j=i+1;s[j]!='\0';j++)
			printf("%c",s[j]);
		printf("e%d",-n);
	}
	else if(s[1]=='.')
		printf("%se0",s);
	else{
		printf("%c.",s[0]);
		for(i=1;s[i]!='\0';i++){
			if(s[i]!='.')
				printf("%c",s[i]);
			else n=i-1;
		}
		printf("e%d",n);			
	}
	return 0;
}

