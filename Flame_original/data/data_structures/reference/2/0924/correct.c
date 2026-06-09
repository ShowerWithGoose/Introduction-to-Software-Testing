#include <stdio.h>
#include <string.h>
char str1[100], str3[100];
int main()
{
	int flag = 0;
	int i, j = 0, k = 0, len, n;
	int a[100] = { 0 }, b, c, d;
	gets(str1);
	len = strlen(str1);
	for (i = 0;i <= len;i++)
	{
		while (str1[i] >= '0' && str1[i] <= '9')
		{
			a[j] = a[j] * 10 + str1[i] - '0';
			i++;
			flag = 1;
		}
		if (flag == 1)
			j++;
		flag = 0;
		if ((str1[i] == '+') || (str1[i] == '-') || (str1[i] == '*') || (str1[i] == '/'))
		{
			str3[k] = str1[i];
			k++;
		}
	}
	for (i = 0;i < len;i++)
	{

		if (str3[i] == '*')
		{
			a[i] = a[i] * a[i + 1];

			for (n = i;n <= len;n++)
			{
				a[n + 1] = a[n + 2];
				str3[n] = str3[n + 1];
			}
			i = -1;
		}
		if (str3[i] == '/')
		{
			a[i] = a[i] / a[i + 1];

			for (n = i;n <= len;n++)
			{
				a[n + 1] = a[n + 2];
				str3[n] = str3[n + 1];
			}
			i = -1;
		}
	}
	for (i = 0;i < len;i++)
	{

		if (str3[i] == '+')
		{
			a[i] = a[i] + a[i + 1];
			for (n = i;n <= len;n++)
			{
				a[n + 1] = a[n + 2];
				str3[n] = str3[n + 1];
			}
			i = -1;
		}
		if (str3[i] == '-')
		{
			a[i] = a[i] - a[i + 1];
			for (n = i;n <= len;n++)
			{
				a[n + 1] = a[n + 2];
				str3[n] = str3[n + 1];
			}
			i = -1;
		}
	}
	printf("%d", a[0]);
	return 0;
}

