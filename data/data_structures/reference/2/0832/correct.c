#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#define eps 1e-6
char a[101], b[51];
int c[51];
int main()
{
	fgets(a, 101, stdin);
	int i = 0, j = 0, k = 0, m = 0, len = strlen(a), n = 0, t = 0, d = 0;
	for (i = 0; i < len; i++)
	{
		if (a[i] == '+' || a[i] == '-' || a[i] == '*' || a[i] == '/' || a[i] == '=')
		{
			b[j] = a[i];
			j++;
		}
		else if (a[i] >= '0' && a[i] <= '9')
		{
			for (k = i; a[k] >= '0' && a[k] <= '9'; k++)
			{
				c[t] = 10 * c[t] + a[k] - '0';
			}
			i += (k - i - 1);
			t++;
		}
	}
	/*for (t = 0; t < sizeof(c); t++)
	{
		printf("%d ", c[t]);
	}
	for (j = 0; j < strlen(b); j++)
	{
		printf("%c ", b[j]);
	}*/
	for (i = 0; i < strlen(b); i++)
	{
		if (b[i] == '-')
		{
			c[i + 1] = ~c[i + 1] + 1;
		}
		if (b[i] == '*')
		{
			c[i + 1] *= c[i];
			c[i] = 0;
		}
		if (b[i] == '/')
		{
			c[i + 1] = c[i] / c[i + 1];
			c[i] = 0;
		}
	}
	for (i = 0;i < strlen(b); i++)
	{
		d += c[i];
	}
	printf("%d", d);
	return 0;
}


