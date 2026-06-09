#include <stdio.h>
#include <string.h>
int main()
{
	char s[200];
	int i=0,f1,f2;
	gets(s);
	if(s[0]=='0'){
		for(i=2;s[i]!='\0';i++){
			if(s[i]!='0'){
				f1=i;break;
				}
		}
		if(f1==strlen(s)-1)
		printf("%c",s[f1]);
		else if(f1!=strlen(s)-1)
		printf("%c.",s[f1]);
		for(i=f1+1;s[i]!='\0';i++)
		printf("%c",s[i]);
		printf("e-%d",f1-1);
	}
	else if(s[0]!='0'){
		for(i=0;s[i]!='\0';i++){
		if(s[i]=='.'){
		f2=i;break;}
		}
		printf("%c.",s[0]);
		for(i=1;s[i]!='.';i++)
		printf("%c",s[i]);
		for(i=f2+1;s[i]!='\0';i++)
		printf("%c",s[i]);
		printf("e%d",f2-1);
	}
	return 0;
}



