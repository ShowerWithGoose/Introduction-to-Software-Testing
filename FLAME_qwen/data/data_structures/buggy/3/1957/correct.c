#include <stdio.h>
#include <string.h>
char s[110];
int main()
{
	gets(s);
	int len=strlen(s),a;
	if(s[0]=='0'){
		for(int i=2;i<len;i++){
			if(s[i]!='0'){
				a=i;
				break;
			}
		}
		if(a==len-1){
			printf("%ce-%d",s[a],a-1);
		}else{
			printf("%c.",s[a]);
		for(int i=a+1;i<len;i++){
			printf("%c",s[i]);
		}
		printf("e-%d",a-1);
		}
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

