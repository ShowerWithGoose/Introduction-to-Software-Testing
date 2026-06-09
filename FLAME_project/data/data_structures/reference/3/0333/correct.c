#include <stdio.h>
#include <string.h>
char num[105];
int main()
{
	gets(num);
	int i;
	int point=0;
	int len;
	len=strlen(num);
	if(num[0]!='0')
	{
		printf("%c.",num[0]);
		for(i=1;i<len;i++)
		{
			if(num[i]!='.')
			printf("%c",num[i]);
			else
			point=i;
		}
		printf("e%d",point-1);
	}
	else
	{
		for(i=2;i<len;i++)
		{
			if(num[i]!='0'&&i!=len-1)
			{
				printf("%c.",num[i]);
				point=i;
				break;
			}
			else if(num[i]!='0'&&i==len-1)
			{
				printf("%c",num[i]);
				point=i;
				break;
			}
		}
		for(i=point+1;i<len;i++)
		{
			printf("%c",num[i]);
		}
		printf("e-%d",point-1);
	}
	return 0;
}
