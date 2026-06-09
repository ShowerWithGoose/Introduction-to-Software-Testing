#include<stdio.h>
#include<string.h>
char s[10000];
int main()
{
	gets(s);
	int i,l=strlen(s);
	for(i=0;i<l;i++)
	{
		if(s[i]=='.')
		break;
	}
	if(i>1)
	{
		int j;
		printf("%c.",s[0]);
		for(j=1;j<i;j++)
		printf("%c",s[j]);
		for(j=i+1;j<l;j++)
		printf("%c",s[j]);
		printf("e%d",i-1);
	}
	else if(s[i-1]=='0')
	{
		int j;
		for(j=2;j<l;j++)
		{
			if(s[j]!='0')
			break;
		}
		int k=j;
		printf("%c",s[j]);
		if(j<l-1)
		printf(".");
		j++;
		for(;j<l;j++)
		{
			printf("%c",s[j]);
		}
		printf("e-%d",k-1);
	}
	else
	{
		printf("%se0",s);
	}
	return 0;
}



