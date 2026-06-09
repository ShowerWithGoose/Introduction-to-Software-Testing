#include<stdio.h>
#include<string.h>

int main()
{
	char s[10000];
	int i,j;
	scanf("%s",&s);
	for(i=0;i<strlen(s);i++)
	{
		if(s[i]!='-')
		{
			printf("%c",s[i]);
		}
		else if(s[i]=='-')
		{
			if((s[i-1]>=65&&s[i+1]<=90)||(s[i-1]>=97&&s[i+1]<=122)||(s[i-1]>=48&&s[i+1]<=57))
			{
				for(j=1;j<s[i+1]-s[i-1];j++)
				{
					printf("%c",s[i-1]+j);
				}
			}
			else
			{
				printf("-");
			}
		}
	}
	return 0;
 } 

