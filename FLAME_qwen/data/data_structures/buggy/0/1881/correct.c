#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<string.h>
#include<math.h>
char str[100000];
int alpha(char a, char b);
int main()
{
	int i;
	char* p;
	gets(str);
	int len = strlen(str);
	for (i = 0; i <= (strlen(str) - 1); i++)
		if (str[i + 1] == '-' && alpha(str[i],str[i+2])!=0)
		{
			for (p = str[i]; p < str[i + 2]; p++)
				{
					printf("%c", p);
				}
			if (p == str[i])
			{
				printf("%c%c", str[i], str[i + 2]);
			}
			i++;
		}
		else
		{
			printf("%c", str[i]);
		}
}
alpha(char a, char b)
{
	if ((a - 'a') < 26 && (b - 'a') < 26 && (b - 'a') >= 0 && (a - 'a') >=0)
		return 1;
	else if ((a - 'A') < 26 && (b - 'A') < 26 && (b - 'A') >=0 && (a - 'A')>=0)
		return 2;
	else if ((a - '0') < 10 && (b - '0') < 10 && (b - '0') >=0 && (a - '0') >=0)
		return 3;
	else
		return 0;
}
