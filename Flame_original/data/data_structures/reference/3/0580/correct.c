#include <stdio.h>
#include <string.h>
int main()
{
	int len,i,j;
	char s[1000];
	scanf("%s",s);
	len=strlen(s);
	if(s[1]=='.')
	{
		if(s[0]!='0')
		{
			for(i=0;i<len;i++)
			{
				printf("%c",s[i]);
			}
			printf("e0");
		}
		else
		{
			j=1;
			for(i=2;i<len && s[i]=='0';i++)
			{
				j++;
			}
			printf("%c",s[i]);
			if(i+1==len)
			{
				printf("e-%d",j);
			}
			else
			{
				printf(".");
				for(i++;i<len;i++)
				{
					printf("%c",s[i]);
				}
				printf("e-%d",j);
			}
		}
	}
	else
	{
		for(j=0;s[j]!='.';)
		{
			j++;
		}
		j--;
		printf("%c.",s[0]);
		for(i=1;i<len;i++)
		{
			if(s[i]!='.')
			{
				printf("%c",s[i]);
			}
		}
		printf("e%d",j);
	}
	return 0;
} 



