#include <stdio.h>
#include <string.h>
int main()
{
	char str[110];
	gets(str);
	int i,n,m=0,t=0,j=0;
	m=strlen(str);
	for(i=0;i<m;i++)
	{
		if(str[i]=='.')
		{
			n=i;
			break;
		}
		else if(str[i]!='.')
		{
			j++;
		}
	}
	if(j!=m)
	{
	if(n==1)
	{
		if(str[0]!='0')
		{
			printf("%se0",str);
		}
		else if(str[0]=='0')
		{
			for(i=2;i<m;i++)
			{
				if(str[i]=='0')
				{
					t++;
				}
				else if(str[i]!='0')
				{
					break;
				}
			}
			if(t!=m-3)
			printf("%c.",str[t+2]);
			else
			printf("%c",str[t+2]);
			for(i=t+3;i<m;i++)
			{
				printf("%c",str[i]);
			}
			printf("e-%d",t+1);
			
		}
	}
	else if(n!=1)
	{
		printf("%c.",str[0]);
		for(i=1;i<m;i++)
		{   if(str[i]!='.')
			printf("%c",str[i]);
		}
		printf("e%d",n-1);
	}
	}
	else if(j==m)
	{
		printf("%c.",str[0]);
		for(i=1;i<m;i++)
		{
			printf("%c",str[i]);
		}
		printf("e%d",m-1);
	}
	return 0;
}

