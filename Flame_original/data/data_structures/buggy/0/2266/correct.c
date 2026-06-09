#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<time.h>
int main()
{
	char str[1002];
	gets(str);
	int len=strlen(str);
	int flag=0;
	for(int i=0;i<len;i++)
	{
		flag=0;
		if(str[i]=='-')
		{
			if(str[i-1]<='z'&&str[i-1]>='a')
			{
				if(str[i+1]<='z'&&str[i+1]>='a')
				{
					if(str[i-1]<=str[i+1])
					{
						flag=1;
						int max=str[i+1]-str[i-1];
						for(int j=1;j<max;j++)
						{
							printf("%c",str[i-1]+j);
						}
					}
				}
			}
			if(str[i-1]<='Z'&&str[i-1]>='A')
			{
				if(str[i+1]<='Z'&&str[i+1]>='A')
				{
					if(str[i-1]<=str[i+1])
					{
						flag=1;
						int max=str[i+1]-str[i-1];
						for(int j=1;j<max;j++)
						{
							printf("%c",str[i-1]+j);
						}
					}
				}
			}
			if(str[i-1]<='9'&&str[i-1]>='0')
			{
				if(str[i+1]<='9'&&str[i+1]>='0')
				{
					if(str[i-1]<=str[i+1])
					{
						flag=1;
						int max=str[i+1]-str[i-1];
						for(int j=1;j<max;j++)
						{
							printf("%c",str[i-1]+j);
						}
					}
				}
			}
			if(flag==0)
			printf("-");
		}
		else
		{
			printf("%c",str[i]);
		}
	}
	return 0;
}



