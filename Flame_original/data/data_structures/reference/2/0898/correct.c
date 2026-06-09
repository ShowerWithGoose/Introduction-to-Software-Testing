#include<stdio.h>
#include<string.h>
char s[100000];
char p[100000];
char c[100000];
int arr[100000];
int j = 1;
int flag = 0;
int main()
{
	int a;
	gets(p);
	int k = strlen(p);
	int n = 0;
	for (int i = 0;i < k;i++)
	{
		if (p[i] != ' ' && p[i] != '=')
		{
			s[n] = p[i];
			n++;
		}
	}
	 n=strlen(s);
	for (int i = 0;i < n;i++)
	{
		int b = 0;
		while (s[i] >= '0' && s[i] <= '9')
		{
			b = b * 10 + s[i] - '0';
			i++;
			flag = 1;
		}
		if (flag == 1)
		{
			arr[j] = b;
			j++;
		}	
	}
	j = 0;
	for (int i = 0;i < n;i++)
	{
		int b = 0;
		if (s[i]=='*' || s[i] == '/'|| s[i] == '+' || s[i] == '-')
		{
			c[j] = s[i];
			j++;
		}
	}
	int count = 1;
	while (count== 1)
	{
		count = 0;
		int i = 1;
		for (i = 0;i < strlen(c);i++)
		{
			if (c[i] == '*')
			{
				arr[i+1] = arr[i+1] * arr[i + 2];
				for (int q = i + 2;q < strlen(c) + 1;q++)
				{
					arr[q] = arr[q + 1];
				}
				break;
			}
			else if (c[i] == '/')
			{
				arr[i+1] = arr[i+1] / arr[i + 2];
				for (int q = i+2;q < strlen(c) + 1;q++)
				{
					arr[q] = arr[q + 1];
				}
				break;
			}
		}
		for (int j = i;j < strlen(c);j++)
		{
			c[j] = c[j + 1];
		}
		for (int i = 0;i < strlen(c);i++)
		{
			if (c[i] == '*' || c[i] == '/')
			{
				count = 1;
				break;
			}
		}
	}
	count = 1;
	while (count == 1)
	{
		count = 0;
		int i = 1;
		for (i = 0;i < strlen(c);i++)
		{
			if (c[i] == '+')
			{
				arr[i + 1] = arr[i + 1] + arr[i + 2];
				for (int q = i + 2;q < strlen(c) + 1;q++)
				{
					arr[q] = arr[q + 1];
				}
				break;
			}
			else if (c[i] == '-')
			{
				arr[i + 1] = arr[i + 1] - arr[i + 2];
				for (int q = i + 2;q < strlen(c) + 1;q++)
				{
					arr[q] = arr[q + 1];
				}
				break;
			}
		}
		for (int j = i;j < strlen(c);j++)
		{
			c[j] = c[j + 1];
		}
		for (int i = 0;i < strlen(c);i++)
		{
			if (c[i] == '+' || c[i] == '-')
			{
				count = 1;
				break;
			}
		}
	}
	printf("%d", arr[1]);
	return 0;
}





