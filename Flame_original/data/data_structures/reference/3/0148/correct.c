#include<stdio.h>
#include<string.h>


int main()
{
	char s[105];
	int i,flag=0,j;
	gets(s);
	for(i=0;i<=strlen(s)-1;i++)
	{
		if(s[i]=='.')
		{
			flag++;
			i=1000;
		}
	}
	if(flag==0)
	{
		if(strlen(s)!=1)
		{
			printf("%c.",s[0]);
			for(i=1;i<=strlen(s)-1;i++)
			{
				printf("%c",s[i]);
			}
			printf("e%d",strlen(s)-1);
		}
		else
		{
			printf("%ce0",s[0]);
		}
	}
	else
	{
		if(s[0]=='0')
		{
			for(i=2;i<=strlen(s)-1;i++)
			{
				if(s[i]!='0')
				{
					j=i;
					i=105;
				}
			}
			if(j!=strlen(s)-1)
			{
				printf("%c.",s[j]);
				for(i=j+1;i<=strlen(s)-1;i++)
				{
					printf("%c",s[i]);
				}
				printf("e-%d",j-1);
			}
			else
			{
				printf("%ce-%d",s[j],j-1);
			}
		}
		else
		{
			if(s[1]=='.')
			{
				printf("%s",s);
				printf("e0");
			}
			else
			{
				for(i=0;i<=strlen(s)-1;i++)
				{
					if(s[i]=='.')
					{
						j=i;
						i=105;
					}
				}
				printf("%c.",s[0]);
				for(i=1;i<=j-1;i++)
				{
					printf("%c",s[i]);
				}
				for(i=j+1;i<=strlen(s)-1;i++)
				{
					printf("%c",s[i]);
				}
				printf("e%d",j-1);
			}
		}
		
	}
	
	return 0;
}

