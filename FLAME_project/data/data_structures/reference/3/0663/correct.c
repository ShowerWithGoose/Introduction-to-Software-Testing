#include<stdio.h>
int main()
{
	char s[100];
	int dot,last;
	gets(s);
	for(int i=0;i<strlen(s);i++){
		if(s[i]=='.'){
			dot=i+1;
			break;
		}
	}
	if(dot>=2&&s[0]!='0'){
		printf("%c.",s[0]);
		for(int j=1;j<strlen(s);j++){
			if(s[j]!='.')printf("%c",s[j]);
		}
		printf("e%d",dot-2);
	}
	if(dot=2&&s[0]=='0'){
		for(int i=dot+1;i<strlen(s);i++){
			if(s[i]!='0'){
				last=i+1;
				break;
			}
		}
		if(last==strlen(s)){
			printf("%ce-%d",s[last-1],last-1-dot);
		}
		else{
			printf("%c.",s[last-1]);
			for(int i=last;i<strlen(s);i++){
				printf("%c",s[i]);
			}
			printf("e-%d",last-1-dot);
		}
	}
	return 0;
}




