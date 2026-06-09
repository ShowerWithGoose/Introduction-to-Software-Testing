#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
	char number[200];
	int pointss=0, len, i, judge1=0, judge2=0, len2;
	
	scanf("%s",number);
	
	if(number[0] == '0')
	{
		for(i=2; i<=strlen(number)-2; i++)
		{
			if(number[i] != '0')
				judge1 = 1;
		}
		if(judge1 == 0)
		{
			len = strlen(number)-2;
			printf("%ce-%d",number[strlen(number)-1],len);
		}
		else
		{
			for(i=2; i<=strlen(number)-1;i++)
			{
				if(number[i] != '0' && judge2 != 1)
				{
					printf("%c.",number[i]);
					judge2 = 1;
					len2 = i-1;
				}
				else
				{
					if(judge2 != 0)
						printf("%c",number[i]);
				}
			}
			printf("e-%d",len2);
		}
	}
	else
	{
		if(number[1] == '.')
		{
			printf("%se0",number);
		}
		else
		{
			for(i=1; i<=strlen(number)-1; i++)
			{
				if(number[i] == '.')
					pointss = i;
			}
			printf("%c.",number[0]);
			for(i=1; i<pointss; i++)
			{
				printf("%c",number[i]);
			}
			for(i=pointss+1; i<=strlen(number)-1; i++)
			{
				printf("%c",number[i]);
			}
			printf("e%d",pointss-1);
		}
	}
	return 0;
}


