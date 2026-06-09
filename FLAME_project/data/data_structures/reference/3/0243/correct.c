#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
char a[110];
int main()
{
	int i,j,k;
	gets(a);
	int len=strlen(a);
	int cnt=0;
	int flag=0;
	if(a[0]=='0')
	{
		for(i=2;i<len;i++)
		{
			while(a[i]=='0')
			{
				cnt++;
				i++;
			}
			if(a[i]!='0')
			{
				if(a[i+1]=='\0')
				{
					printf("%ce-%d",a[i],cnt+1);
				}
				else
				{
					printf("%c.",a[i]);
					i++;
					while(a[i]!='\0')
					{
						printf("%c",a[i]);
						i++;
					}
					printf("e-%d",cnt+1);
				}
			}
		}
	}
	else if(a[0]!='0')
	{
		if(a[1]=='.')
		{
			printf("%se0",a);
		}
		else
		{
			cnt=0;
			for(i=0;i<len;i++)
			{
				if(a[i]!='.')
				{
					cnt++;
				}
				else if(a[i]=='.')
				{
					break;
				}
			}
			for(i=0;i<len;i++)
			{
				if(a[i]=='.')
				{
					flag=1;
				}
			}
			if(flag==0)
			{
				printf("%c.",a[0]);
				for(i=1;i<len;i++)
				{
					printf("%c",a[i]); 
				}
				printf("e%d",len-1);
			}
			else if(cnt!=0)
			{
				printf("%c.",a[0]);
				for(i=1;a[i]!='.';i++)
				{
					printf("%c",a[i]);
				}
				for(i=i+1;a[i]!='\0';i++)
				{
					printf("%c",a[i]);
				}
				printf("e%d",cnt-1);
			}
		}
	}
	return 0;
 } 

