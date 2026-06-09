#include <stdio.h>
#include <string.h>
char s[110];
int main()
{
	gets(s);
	int len=strlen(s),a;
	if(s[0]=='0'){
		printf("%ce-%d",s[len-1],len-2);
	} else if(s[0]!='0'&&s[1]=='.'){
		printf("%se0",s);
	} else if(s[0]!='0'&&s[1]!='.'){
		for(int i=0;i<len;i++){
			if(s[i]=='.'){
				a=i;
			}
		}
		printf("%c.",s[0]);
		for(int i=1;i<len;i++){
			if(s[i]!='.'){
				printf("%c",s[i]);
			}
		}
		printf("e%d",a-1);
	}
	return 0;
}

