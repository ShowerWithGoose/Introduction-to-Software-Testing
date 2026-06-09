#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#define N 100

int main()
{
	int i, n, up = 0, j, p = 1, new;
	char point[N];
	gets(point);
	n = strlen(point);
	if (point[0] == '0')
	{
		for (i = 2; i < n; i++)
		{
			if (point[i] == '0')
			{
				up++;
			}
			else
			{
				break;
			}
		}
		up++;
		for (j = i; j < n; j++)
		{
			printf("%c", point[j]);
			p++;
			if (j!=n-1&&p == 2)//要不然0.9就输出9.e-1了
			{
				printf(".");
			}
		}
		printf("e-%d", up);
	}

	else
	{
		for (i = 0; i < n; i++)
		{
			if (point[i] != '.')
			{
				printf("%c", point[i]);
				up++;
				p++;
				if (p == 2)
				{
					printf(".");
				}
			}
			else
			{
				new = up;
			}
		}
		new--;
		printf("e%d", new);
	}
	return 0;
}
