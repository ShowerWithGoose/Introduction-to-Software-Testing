#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int bbq(char m)
{
	if ((m >= 'a' && m <= 'z') || (m >= 'A' && m <= 'Z'))
		return 0;
	else
		return 1;
}
int bbb(char m)
{
	if (m >= 'A' && m <= 'Z')
		return 1;
	else
		return 0;
}
char* s_gets(char* st, int n)
{
	char* ret_val;
	int i = 0;
	ret_val = fgets(st, n, stdin);
	if (ret_val)
	{
		while (st[i] != '\n' && st[i] != '\0')
			i++;
		if (st[i] == '\0')
			st[i] = '\0';
	}
	else
		return ret_val;
}
char a[1000][1000] = { 0 };
char b[1000] = { 0 };
char c[1000][1000] = { 0 };
char d[1000][1000] = { 0 };
int geshu[1000] = { 0 };
int n = 0, i, len, j, p = 0, q = 0, m = 0;
int main()
{
	freopen("article.txt", "r", stdin);
	while (s_gets(b, sizeof(b)) != NULL)
	{
		strcpy(a[n], b);
		n++;
	}
	for (i = 0; i < n; i++)
	{
		q = 0;
		len = strlen(a[i]);
		for (j = 0; j < len; j++)
		{
			if (bbq(a[i][j]))
			{
				p++;
				q -= q;
			}
			else
			{
				c[p][q] = a[i][j];
				q++;
			}
		}
	}
	for (i = 0; i < p; i++)
	{
		len = strlen(c[i]);
		for (j = 0; j < len; j++)
		{
			if (bbb(c[i][j])) 
			{
				c[i][j] = c[i][j] + 'a' - 'A';
			}
		}
	}
	for (i = 0; i < p; i++)
	{
		for (j = 0; j < p - i - 1; j++)
		{
			if (strcmp(c[j], c[j + 1]) > 0)
			{
				char ch[1000];
				strncpy(ch, c[j],1000);
				strncpy(c[j], c[j + 1],1000);
				strncpy(c[j + 1], ch,1000);
			}
		}
	}
	for (i = 0; i <1000; i++)
		geshu[i] = 1;
	for (i = 0; i < p; i++)
	{
		if (strcmp(c[i], c[i + 1]) != 0)
		{
			strncpy(d[m], c[i],1000);
			m++;
		}
		else geshu[m]++;
	}
	for (i = 1; i < m; i++)
	{
		printf("%s %d\n", d[i], geshu[i]);
	}
	fclose(stdin);
	return 0;
}


