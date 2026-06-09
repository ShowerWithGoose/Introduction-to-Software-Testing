#include<stdio.h>
#include<string.h>
int main()
{
	char s[1000];
	gets(s);
	int str = strlen(s);
	int flag,i;
	int zero;
	for(i=0;i<str;i++){
		if(s[i] == '.'){
			flag = i - 1;
			break;
		}
	}
	if(s[0] == '0'){
		for(i=0;i<str;i++){
			if(s[i]!='0'&&s[i]!='.'){
				zero = i-1;
				break;
			}
		}
		if(zero+2!=str) printf("%c.",s[zero+1]);
		else printf("%c",s[zero+1]);
		for(i=zero+2;i<str;i++)
			printf("%c",s[i]);
		printf("e-");
		printf("%d",zero);	
	}
	
	else{
		printf("%c.",s[0]);
		for(i=1;i<=flag;i++)
			printf("%c",s[i]);
		for(i=flag+2;i<str;i++)
			printf("%c",s[i]);
		printf("e");
		printf("%d",flag);
	}
	
	return 0;
 } 



