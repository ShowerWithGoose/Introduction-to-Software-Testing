#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int f(char a, char b)
{
	if (a >= 'a' && a <= 'z' && b >= 'a' && b <= 'z' && a < b)
		return 1;
	else if (a >= 'A' && a <= 'Z' && b >= 'A' && b <= 'Z' && a < b)
		return 1;
	else if (a >= '0' && a <= '9' && b >= '0' && b <= '9' && a < b)
		return 1;
	else
		return 0;
}
int main()
{
	char s[1000] = { 0 };
	gets(s);
	int n = strlen(s);
	for (int i = 0;i < n;i++)
	{
		if (s[i] == '-')
		{
			if (f(s[i - 1], s[i + 1]) == 0)
				printf("-");
			else
			{
				
				for (char j = s[i - 1]+1;j <s[i + 1];j++)
					printf("%c", j);
			}
		}
		else
			printf("%c", s[i]);
	}
}









