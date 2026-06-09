#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

char str[200];

int main()
{
	int i=0,j=0,cnt_f=0,cnt_b=0,flag=0;
	
	while(str[i]=getchar())
	{
		if(str[i]=='\n')
		{
			break;
		}
		if(str[i]=='.')
		{
			flag=1;
		}
		if(flag==0)
		{
			cnt_f++;
		}
		else
		{
			cnt_b++;
		}
		i++;
	}
	
	if(str[0]=='0')
	{
		for(i=2;i<strlen(str);i++)
		{
			if(str[i]!='0')
			{
				printf("%c",str[i]);
				break;
			}
		}
		if(i<strlen(str)-2)
		{
			printf(".");
		}
		for(j=i;j<strlen(str)-2;j++)
		{
			printf("%c",str[j]);
		}
		printf("e-%d",i-1);
	}
	else if(str[0]!='-')
	{
		printf("%c.",str[0]);
		for(i=1;i<strlen(str)-1;i++)
		{
			if(str[i]=='.')
			{
				continue;
			}
			printf("%c",str[i]);
		}
		printf("e%d",cnt_f-1);
	}
	else
	{
		printf("-");
		if(str[1]=='0')
		{
			for(i=3;i<strlen(str);i++)
			{
				if(str[i]!='0')
				{
					printf("%c",str[i]);
					break;
				}
			}
			if(i<strlen(str)-2)
			{
				printf(".");
			}
			for(j=i;j<strlen(str)-2;j++)
			{
				printf("%c",str[j]);
			}
			printf("e-%d",i-2);
		}
		else
		{
			printf("%c.",str[1]);
			for(i=2;i<strlen(str)-1;i++)
			{
				if(str[i]=='.')
				{
					continue;
				}
				printf("%c",str[i]);
			}
			printf("e%d",cnt_f-2);
		}
	}
    return 0;
}

