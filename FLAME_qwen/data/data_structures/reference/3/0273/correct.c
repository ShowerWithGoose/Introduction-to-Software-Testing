#include<stdio.h>
#include<string.h>
char s[1000000];
int main(){
	int i,j,flag;
	gets(s);
	if(s[0]!='0'&&s[1]=='.') {
		for(i=0;i<strlen(s);i++) printf("%c",s[i]);
		printf("e0");
		return 0;
	}
	if(s[0]=='0'&&s[1]=='.'){
		for(i=2;i<strlen(s);i++) if (s[i]!='0'){
			if(s[i+1]=='\0') printf("%c",s[i]);
			else printf("%c.",s[i]);
			for(j=i+1;j<strlen(s);j++) printf("%c",s[j]);
			printf("e");
			printf("%d",1-i);
			break;
		}
		return 0;
	}
	printf("%c.",s[0]);
	for(i=1;i<strlen(s);i++) if(s[i]!='.') printf("%c",s[i]);
								else flag=i;
	printf("e%d",flag-1);
	return 0;
} 

