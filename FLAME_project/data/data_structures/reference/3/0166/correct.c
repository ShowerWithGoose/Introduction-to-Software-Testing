#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int main()
{
	char str[50] = { 0 }, ans[50] = { 0 };
	int i, j, k, m, done;
	gets(str);
	if (str[0] == '0')
	{
		k = 0;
		i = strchr(str, '.') - str;
		j = i;
		while (str[j + 1] == '0')
		{
			str[j] = str[j + 1];
			str[j + 1] = '.';
			j++;
			k++;
		}
		str[j] = str[j + 1];
		str[j + 1] = '.';
		j++;
		k++;
		if (j == strlen(str) - 1)
		{
			str[j] = '\0';
		}
		done = 0;
		for (m = 0; m < strlen(str); m++)
		{
			if (str[m] != '0')
			{
				done = 1;
			}
			if (done)
			{
				printf("%c", str[m]);
			}
		}
		printf("e%d", -k);
	}
	else
	{
		k = 0;
		i = strchr(str, '.') - str;
		j = i;
		while (j>1)
		{
			str[j] = str[j - 1];
			str[j - 1] = '.';
			j--;
			k++;
		}
		for (m = 0; m < strlen(str); m++)
		{
			printf("%c", str[m]);
		}
		printf("e%d", k);
	}
	return 0;
}
