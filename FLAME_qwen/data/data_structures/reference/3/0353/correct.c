#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int main()
{
	char s[110];
	gets(s);
	int len = strlen(s),i,dot,f0,len1,zero;
	for(i = 0; i <= len - 1; i++)
	{
		if(s[i] == '.')
		{
			dot = i;
			break;
		}
	}
	if(dot == 1)
	{
		if(s[0] == '0')
		{
			for(i = 2; i < len; i++)
			{
				if(s[i] != '0')
				{
					f0 = i;
					break;
				}
			}
			len1 = len - f0;
			zero = f0 - 1;
			if(len1 == 1)
				printf("%ce-%d",s[f0],zero);
			else
			{
				printf("%c.",s[f0]);
				for(i = f0 + 1; i <= len - 1; i++)
					printf("%c",s[i]);
				printf("e-%d",zero);
			}
		}
		else
		{
			for(i = 0; i < len; i++)
				printf("%c",s[i]);
			printf("e0");
		}
	}
	else
	{
		zero = dot - 1;
		printf("%c.",s[0]);
		for(i = 1; i < dot; i++)
			printf("%c",s[i]);
		for(i = dot +1; i < len; i++)
			printf("%c",s[i]);
		printf("e%d",zero);
	}













	return 0;
}


