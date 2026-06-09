#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
char s[108];
int main()
{
	int i, l, ci = 0;
	gets(s);
	l = strlen(s);
	if (strchr(s, '.')-s == 1)
	{
		if (s[0] == '0')
		{
			for (i = 2; s[i] == '0'; i++)
			{
				ci++;
			}
			printf("%c", s[2+ci]);
			if (i == l-1)
			{
				printf("e-%d", ci+1);
			}
			else
			{
				printf(".");
				for (i += 1; i < l; i++)
				{
					
					printf("%c", s[i]);
				}
				printf("e-%d", ci+1);
			}
		}
		else
		{
			printf("%s", s);
			printf("e0");
		}
	}
	else
	{
		
			printf("%c.", s[0]);
			for (i = 1; i < strchr(s, '.')-s; i++)
			{
				printf("%c", s[i]);
			}
			for (i = strchr(s, '.')-s+1; i < l; i++)
			{
				printf("%c", s[i]);
			}
			printf("e%d", strchr(s, '.')-s-1);
		
	}
	return 0;
}


