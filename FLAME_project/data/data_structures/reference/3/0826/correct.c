#include<stdio.h>
#include<string.h>
int main()
{
	char s[10005];
	gets(s);
	int i=0,j=0,l;
	l=strlen(s);
	if(s[0]=='0')
	{
		for(i=2;i<l-1;i++)
		{
			if(s[i]=='0')
			j++;
			else
			break;
		}
		if(j+3==l)
		printf("%c",s[j+2]);
		else
		{
			printf("%c.",s[j+2]);
		for(i=j+3;i<l;i++)
		{
			printf("%c",s[i]);
		}
		}
		printf("e-%d",j+1);
	}
	else
	{
		for(i=0;i<l-1;i++)
		{
			j++;
			if(s[i]=='.')
			break;
		}
		printf("%c.",s[0]);
		if(j==2)
		{
			for(i=2;i<l;i++)
			printf("%c",s[i]);
		}
		else
		{
			for(i=1;i<j-1;i++)
			printf("%c",s[i]);
			for(i=j;i<l;i++)
			printf("%c",s[i]);
		}
		printf("e%d",j-2);
	}
	return 0;
 } 

