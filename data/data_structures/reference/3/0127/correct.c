#include <stdio.h>
#include <string.h>
int main()
{
	char s[1000];
	int k=0,flag=0;
	int i=0;
	gets(s);
	if(s[0]=='0')
	{
		for(i=1;i<strlen(s);i++)
		{
			if(s[i]=='0'||s[i]=='.')
			{
				k++;
			}
			else
			{
				break;
			}
		}
		for(;i<strlen(s);i++)
		{
			printf("%c",s[i]);
			if(flag==0&&i!=strlen(s)-1)
			{
				printf(".");
				flag=1;
			}
		}
		printf("e-%d",k);
	}
	else
	{
		for(i=1;i<strlen(s);i++)
		{
			if(s[i]!='.')
			{
				k++;
			}
			else
			{
				break;
			}
		}
		for(i=0;i<strlen(s);i++)
		{
			if(s[i]!='.')
			{
				printf("%c",s[i]);
			}
			if(flag==0)
			{
				printf(".");
				flag=1;
			}
		}
		printf("e%d",k);
	}
	return 0;
}

