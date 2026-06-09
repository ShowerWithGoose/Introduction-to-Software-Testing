#include<stdio.h>
#include<string.h>
char s[10000];
int flag=0;
int main()
{
	int i=0,j=0;
	gets(s);
	if(s[0]=='0')
	{
		flag=0;
	}
	else flag=1;
	if(flag==1)
	{
		while(s[i]!='.')
		{
			i++;
		}
		printf("%c.",s[0]);
		for(j=1;j<strlen(s);j++)
		{
			if(s[j]!='.')printf("%c",s[j]);
		}
		printf("e%d",i-1);
		
	}
	if(flag==0)
	{
		while(s[i]=='0'||s[i]=='.')
		{
			i++;
		}
		printf("%c",s[i]);
		if(strlen(s)-1>i)printf(".");
		
		for(j=i+1;j<strlen(s);j++)
		{
			printf("%c",s[j]);
		}
		printf("e-%d",i-1);
	}
	return 0;
	
}



