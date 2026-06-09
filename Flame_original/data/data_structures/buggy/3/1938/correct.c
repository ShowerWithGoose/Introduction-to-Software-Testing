#include <stdio.h>
#include <math.h>
#include <string.h>
char s[110];
int main()
{
	scanf("%s",s);
	int len=strlen(s);
	int i=0,flag=0,flag1=0;
	if(strchr(s,'.')==NULL)
	{
		for(i=len-1;i>=1;i--)
		{
			if(s[i]!='0')
			{
				flag=i;
				break;
			}
		}
		if(flag==0)
		{
			printf("%c",s[0]);
		}
		else
		{
			printf("%c.",s[0]);
			for(i=1;i<=flag;i++)
			{
				printf("%c",s[i]);
			}
		}
		printf("e%d",len-1);
	}
	else
	{
		if(s[0]=='0')
		{
			for(i=0;i<len;i++)
			{
				if(s[i]!='0'&&s[i]!='.')
				{
					flag++;
				}
				if(s[i]!='0'&&s[i]!='.'&&flag1==0)
				{
					flag1=i;
				}
				if(flag==2)
				{
					printf(".");
				}
				if(flag!=0)
				{
					printf("%c",s[i]);
				}
			}
			printf("e%d",1-flag1);
		}
		else
		{
			for(i=0;i<len;i++)
			{
				if(s[i]=='.')
				{
					flag=i;
					break;
				}
			}
			printf("%c",s[0]);
			printf(".");
			for(i=1;i<len;i++)
			{
				if(s[i]!='.')
				printf("%c",s[i]);
			}
			printf("e%d",flag-1);
		}
	}
	return 0;
}

