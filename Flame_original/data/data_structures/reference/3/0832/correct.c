#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#define eps 1e-6
char a[101], b[101];
int main()
{
	scanf("%s", a);
	int len = strlen(a), i, j;
	if (a[0] == '0' && a[1] == '.')
	{
		for (j = 2; j < len; j++)
		{
			if (a[j] != '0')
			{
				if (j == len - 1)
				{
					printf("%ce-%d", a[j], j - 1);
					break;
				}
				else
				{
					printf("%c.", a[j]);
					for (int k = j + 1; k < len; k++)
					{
						printf("%c", a[k]);
					}
					printf("e-%d", j - 1);
					break;
				}
			}
		}
	}
	if (a[0] != '0' && a[1] == '.')
	{
		for (i = 0; i < len; i++)
		{
			printf("%c", a[i]);
		}
		printf("e0");
		}
	if (a[0] != '0' && a[1] != '.')
	{
		for (i = 0; i < len && a[i] != '.'; i++)
		{
			if (i == len - 1)
			{
				printf("%c.", a[0]);
				for (j = 1; j < len; j++)
					printf("%c", a[j]);
				printf("e%d", len - 1);
			}
		}
		for (i = 0; i < len; i++)
		{
			if (a[i] == '.')
			{
				printf("%c.", a[0]);
				for (j = 1; j < i; j++)
					printf("%c", a[j]);
				for (j = i + 1; j < len; j++)
					printf("%c", a[j]);
				printf("e%d", i - 1);
				break;
			}
		}
	}
	return 0;
}


