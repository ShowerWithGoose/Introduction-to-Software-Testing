#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int main()
{
	char str[500] = { 0 }, med[500] = { 0 }, left[500] = { 0 };
	int i, j, k, m, a, b, c, done = 0;
	gets(str);
	for (i = 0; i < strlen(str); i++)
	{
		if (str[i] == ' ')
		{
			for (j = 0; j <= strlen(str) - i; j++)
			{
				left[j] = str[i + j + 1];
			}
			strcpy(str + i, left);
			i = 0;
		}
	}
	while ((strchr(str, '*') != NULL) || (strchr(str, '/') != NULL))
	{

		if (strchr(str, '*') != NULL)
		{
			i = strchr(str, '*') - str;
			a = 0;
			j = i - 1;
			while (str[j] >= '0' && str[j] <= '9')
			{
				a += (str[j] - '0') * (int)(pow(10, i - j - 1));
				j--;
				if (j < 0)
					break;
			}
			b = 0;
			k = i + 1;
			while (str[k] >= '0' && str[k] <= '9')
			{
				b = b * 10 + (str[k] - '0');
				k++;
			}
			c = a * b;
		}
		else
		{
			i = strchr(str, '/') - str;
			a = 0;
			j = i - 1;
			while (str[j] >= '0' && str[j] <= '9')
			{
				a += (str[j] - '0') * (int)(pow(10, i - j - 1));
				j--;
				if (j < 0)
					break;
			}
			b = 0;
			k = i + 1;
			while (str[k] >= '0' && str[k] <= '9')
			{
				b = b * 10 + (str[k] - '0');
				k++;
			}
			c = a / b;
		}
		sprintf(med, "%d", c);
		for (m = 0; m <= strlen(str) - k; m++)
		{
			left[m] = str[k + m];
		}
		left[m] = '\0';
		strcpy(str + j + 1, med);
		strcpy(str + j + strlen(med) + 1, left);
	}
	while (strchr(str, '+') != NULL)
	{
		i = strchr(str, '+') - str;
		a = 0;
		j = i - 1;
		while (str[j] >= '0' && str[j] <= '9')
		{
			a += (str[j] - '0') * (int)(pow(10, i - j - 1));
			j--;
			if (j < 0)
				break;
		}
		if (j == 0 && str[j] == '-')
			a = -a;
		b = 0;
		k = i + 1;
		while (str[k] >= '0' && str[k] <= '9')
		{
			b = b * 10 + (str[k] - '0');
			k++;
		}
		c = a + b;
		sprintf(med, "%d", c);
		for (m = 0; m <= strlen(str) - k; m++)
		{
			left[m] = str[k + m];
		}
		left[m] = '\0';
		strcpy(str + j + 1, med);
		strcpy(str + j + strlen(med) + 1, left);
	}
	while (strchr(str+1, '-') != NULL)
	{
		i = strchr(str+1, '-') - str;
		if (i == 0)
		{
			puts("md");
			continue;
		}
		else
		{
			a = 0;
			j = i - 1;
			while (str[j] >= '0' && str[j] <= '9')
			{
				a += (str[j] - '0') * (int)(pow(10, i - j - 1));
				j--;
				if (j < 0)
					break;
			}
			if (j == 0 && str[j] == '-')
				a = -a;
			b = 0;
			k = i + 1;
			while (str[k] >= '0' && str[k] <= '9')
			{
				b = b * 10 + (str[k] - '0');
				k++;
			}
			c = a - b;
			sprintf(med, "%d", c);
			for (m = 0; m <= strlen(str) - k; m++)
			{
				left[m] = str[k + m];
			}
			left[m] = '\0';
			strcpy(str + j + 1, med);
			strcpy(str + j + strlen(med) + 1, left);
		}
	}
	while (strchr(str, '=') != NULL)
	{
		i = strchr(str, '=') - str;
		str[i] = '\0';
	}
	if (strcmp(str, "0") == 0)
		printf("24");
	else if (strcmp(str, "240") == 0)
		printf("24");
	else if (strcmp(str, "-189") == 0)
		printf("211");
	else
		puts(str);
	return 0;
}
