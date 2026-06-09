#include<stdio.h>
#include<string.h>
char s[100];
int main()
{
	int i,point=0,sum,cnt=0;
	int flag=0;
	int flag1=0;
	scanf("%s",s);
	for(i=0;i<strlen(s);i++)
	{
		if(s[i]=='.')
			point=i;
	}
	if(point==1)
	{
		if(s[0]!='0')
		{
			printf("%se0",s);
		}	
		else
		{
			for(i=2;i<strlen(s);i++)
			{
				if(s[i]!='0'&&flag==0) 
				{
					printf("%c",s[i]);
					sum=i-1;
					flag=1;
				}
				else if(flag==1)
				{
					if(flag1==0)
					{
						printf(".");
						flag1=1;
					}
					printf("%c",s[i]);
				}
			}
			printf("e-%d",sum);
		}
	}
	else
	{
		for(i=strlen(s)-1;i>=1;i--)
		{
			if(s[i]=='0') cnt++;
			else i=0;
		}
		if(cnt<strlen(s)-1) printf("%c.",s[0]);
		else printf("%c",s[0]);
		for(i=1;i<strlen(s)-cnt;i++)
		{
			if(s[i]!='.') printf("%c",s[i]);
		}
		if(point!=0) printf("e%d",point-1);
		else printf("e%d",strlen(s)-1);
	}
 } 

