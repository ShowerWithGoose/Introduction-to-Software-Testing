#include<stdio.h>
#include<string.h>
char s[105];
int main()
{
	gets(s);
	int len=strlen(s);
	if(s[0]=='0')
	{
		for(int i=2;i<len;i++)
		{
			if(s[i]>'0')
			{
				if(i==len-1)
					printf("%ce-%d",s[i],len-2);
				else
				{
					printf("%c.",s[i]);
					for(int j=i+1;j<len;j++)
					printf("%c",s[j]);
					printf("e-%d",i-1);				
				}
				return 0;
			}
		}
	}
	else
	{
		
		if(s[1]=='.')
		printf("%se0",s);
		else
		{
			if(strstr(s,".")!=NULL)
			for(int j=2;j<len;j++)
			{
				if(s[j]=='.')
				{
					printf("%c.",s[0]);
					for(int t=1;t<len;t++)
					{
						if(t!=j)
						printf("%c",s[t]);		
					}
					printf("e%d",j-1);
				}
			}
			else
			{
				printf("%c.",s[0]);
				for(int t=1;t<len;t++)
				printf("%c",s[t]);
				printf("e%d",len-1);
			}
		}
	}
	return 0;
}
