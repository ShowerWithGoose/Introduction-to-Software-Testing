#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
char s[1000007];
int main()
{
	scanf("%s",s);
	int len=strlen(s);
	for(int i=0;i<len;i++)
	{
		if(s[i]!='-')
		{
			printf("%c",s[i]);
		}
		else
		{
			if(isupper(s[i-1])&&isupper(s[i+1])&&s[i+1]>s[i-1])
			{
				int l=s[i+1]-s[i-1]-1;
				for(int j=1;j<=l;j++)
				{
					printf("%c",s[i-1]+j);
				}
			}
			else if(islower(s[i-1])&&islower(s[i+1])&&s[i+1]>s[i-1])
			{
				int l=s[i+1]-s[i-1]-1;
				for(int j=1;j<=l;j++)
				{
					printf("%c",s[i-1]+j);
				}
			}
			else if(isdigit(s[i-1])&&isdigit(s[i+1])&&s[i+1]>s[i-1])
			{
				int l=s[i+1]-s[i-1]-1;
				for(int j=1;j<=l;j++)
				{
					printf("%c",s[i-1]+j);
				}
			}
			else
			printf("-");
		}
	}
	return 0;
}



