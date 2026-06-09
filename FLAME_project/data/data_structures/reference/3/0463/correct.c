#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
	char s[1000];
	int i,j,judge=0,en=-1;
	gets(s);
	for(i=0;s[i]!='.';i++)
	{
		if(s[i]!='0')
		{
			judge=1;
			en++;
		}
		else if(s[i]=='0')
		{
			if(judge==0)
			{
				en=1;
			}
			else if(judge==1)
				en++;
		}
	}
	for(i=0;s[i]!='\0';i++)
	{
		if(s[i]=='.')
			j=i;
	}
	if(judge==0)
	{
		for(i=j+1;s[i]=='0';i++)
			en++;
	}
	if(judge==0)
	{
		while(s[i]=='0'||s[i]=='.')
			i++;	
		if(i==strlen(s)-1)
			printf("%c",s[i]);
		else if(i<strlen(s)-1)
		{
			printf("%c.",s[i]);
			for(j=i+1;s[j]!='\0';j++)
			{
				printf("%c",s[j]);
			}
		}
	}
	else if(judge==1)
	{
		printf("%c.",s[0]);
		for(i=1;s[i]!='\0';i++)
		{
			if(s[i]!='.')
				printf("%c",s[i]);
		}
	}
	if(judge==0)
		printf("e-%d",en);
	else if(judge==1)
		printf("e%d",en);
	return 0;
}

