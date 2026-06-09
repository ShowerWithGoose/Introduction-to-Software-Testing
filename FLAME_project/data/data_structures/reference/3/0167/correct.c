#include <stdio.h>
#include <string.h> 
int main()
{
	char ch[100];
	int m=0,flag=0;
	scanf("%s",ch);
	int len=strlen(ch);
	for(int i=0;i<len;i++)
	{
		if(ch[i]=='.')
		m=i;
	}
	 if(ch[0]=='0')
	{
		for(int i=2;i<len;i++)
		{
			if(ch[i]!='0')
			 {flag=i;
			 break;}
		}
		if(flag==len-1)
		printf("%c",ch[flag]);
		else
		printf("%c.",ch[flag]);
		for(int i=flag+1;i<len;i++)
		{
			printf("%c",ch[i]);
		}
		
		printf("e-%d",flag-1);
	}
	else
	{
		printf("%c.",ch[0]);
		if(m!=0)
		{
		for(int i=1;i<len;i++)
		{
			if(ch[i]=='.')
			{continue;
			}
		printf("%c",ch[i]);}
		printf("e%d",m-1);}
		else
		{
		for(int i=1;i<len;i++)
		{	
		printf("%c",ch[i]);}
		printf("e%d",len-1);}
		}
	
}

