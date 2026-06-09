#include <stdio.h>
#include <ctype.h>
#include <string.h>
char c[1000];

int main()
{
	scanf("%s", c);
	if (c[0] == '0')
	{
		for (int i = 2; i < 1000; i++)
		{
			if (c[i] != '0')
			{
				printf("%c", c[i]);
				if (c[i + 1] == '\0')
				{
					printf("e-%d", i - 1);
				}
				else
				{
					printf(".");
					for (int j = i + 1; c[j] != '\0'; j++)
					{
						printf("%c", c[j]);
					}
					printf("e-%d", i - 1);
				}
				break;
			}
		}
	}
	else
	{
		char* p = strstr(c, ".");
		if (p == NULL)
		{
			int len = strlen(c);
			if (len == 1)
			{
				printf("%ce0", c[0]);
			}
			else
			{
				printf("%c.", c[0]);
				for (int j = 1; c[j] != '\0'; j++)
				{
					printf("%c", c[j]);
				}
				printf("e%d", len - 1);
			}
		}
		else
		{
			int e = p - c - 1;
			printf("%c.", c[0]);
			for (int j = 1; c[j] != '\0'; j++)
			{
				if (c[j] != '.')
				{
					printf("%c", c[j]);
				}
			}
			printf("e%d", e);
		}
	}
	return 0;
}
