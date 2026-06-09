#include <stdio.h>
#include <string.h>
#include <ctype.h>
int in(char s[])
{
	int i;
    for(i=0;i<strlen(s);i++)
    {
    	if(s[i]=='.')return 1;
	}
	return 0;
}
void func(char s[])
{
	int i,j,k,len=strlen(s);
	for(i=0;i<len;i++)
	{
		if(isdigit(s[i])&&s[i]!='0')
		{
			j=i;
			break;
		}
	}
	for(i=0;i<len;i++)
	{
		if(s[i]=='.')
		{
			k=i;
			break;
		}
	}
	if(isdigit(s[0]))
	{
		printf("%c",s[j]);
		if(j!=len-1)printf(".");
		for(i=j+1;i<len;i++)
		{
			if(!isdigit(s[i]))continue;
			printf("%c",s[i]);		
		}
		printf("e%d",k>j?k-j-1:k-j);
	}
	else
	{
		printf("-%c",s[j]);
		if(j!=len-1)printf(".");
		for(i=j+1;i<len;i++)
		{
			if(!isdigit(s[i]))continue;
			printf("%c",s[i]);		
		}
		printf("e%d",k>j?k-j-1:k-j);
	}
}
int main()
{
	int i;
    char s[105];
	gets(s);
    if(in(s)==0)
    {
    	if(isdigit(s[0]))
    	{
    		int l=strlen(s)-1;
    		printf("%c",s[0]);
    		if(strlen(s)!=1)printf(".");
    		for(i=1;i<=l;i++)printf("%c",s[i]);
    		printf("e%d",l);
		}
		else
		{
			int l=strlen(s)-2;
			printf("-%c",s[1]);
			if(strlen(s)!=1)printf(".");
			for(i=2;i<=l+1;i++)printf("%c",s[i]);
			printf("e%d",l);
		}
	}
	else
	func(s);
    return 0;
}

