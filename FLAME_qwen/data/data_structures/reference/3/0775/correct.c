#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
char s[1000];
int a[1000];
int main()
{
	int i,k=-1,j;
	gets(s);
	for(i=0;i<strlen(s);i++)
	{
		if(s[i]=='.')
		{
			k=i;break;
		}
	}
	if(k==-1)
	{
		for(i=0;i<strlen(s);i++)
			printf("%c",s[i]);
	}
	else if(k==1&&s[0]!='0')
	{
		for(i=0;i<strlen(s);i++)
			printf("%c",s[i]);
		printf("e0");
	}
	else if(k==1&&s[0]=='0')
	{
		for(i=2;s[i]=='0';i++);
		j=i;
		if(j==strlen(s)-1)
		{
			printf("%ce-%d",s[j],strlen(s)-2);
		}
		else
		{
			printf("%c.",s[j]);
			for(i=j+1;i<strlen(s);i++)
			{
				printf("%c",s[i]);
			}
			printf("e-%d",strlen(s)-(i-j-1)-2);
		}
	}
	else
	{
		printf("%c.",s[0]);
		for(i=1;i<k;i++)
			printf("%c",s[i]);
		for(i=k+1;i<strlen(s);i++)
			printf("%c",s[i]);
		printf("e%d",k-1);
	}
	return 0;
}

