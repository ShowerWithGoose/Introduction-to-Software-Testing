#include<stdio.h>
#include<string.h>
char s[1000];
int main()
{
	int len,i=0,j=0,del;
	scanf("%s", s);
	len = strlen(s);
	for (; i < len; i++)
	{
		if ('0' < s[i]&&s[i] <= '9')
		{
			break;
		}
	}
	for (; j < len; j++)
	{
		if(s[j]=='.')
		{
			break;
		}
	}
	del = j - i;
	if (del > 0)
	{
		del = del - 1;
	}
	if (i == len - 1)
	{
		printf("%de%d", s[i]-'0', del);
	}
	else
	{
		printf("%d.", s[i] - '0');
		for (int q = i + 1; q < len; q++)
		{
			if (s[q] != '.')
			{
				printf("%d", s[q] - '0');
			}
		}
		printf("e%d", del);
	}
	return 0;
}

