#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#define eps 1e-6
int main()
{
	char s[10000];
	fgets(s, 10000, stdin);
	for (int i = 0; i < strlen(s); i++)
	{
		if (s[i] != '-')
			printf("%c", s[i]);
		else
		{
			if (((s[i - 1] >= 'a' && s[i - 1] <= 'z') && (s[i + 1] > s[i-1] && s[i + 1] <= 'z')) || ((s[i - 1] >= 'A' && s[i - 1] <= 'Z') && (s[i + 1] >s[i-1] && s[i + 1] <= 'Z')) || ((s[i - 1] >= '0' && s[i - 1] <= '9') && (s[i + 1] >s[i-1] && s[i + 1] <= '9')))
			{
				for (char j = s[i - 1] + 1; j < s[i + 1]; j++)
					printf("%c", j);
			}
			else
				printf("-");
		}
	}
	return 0;
}
