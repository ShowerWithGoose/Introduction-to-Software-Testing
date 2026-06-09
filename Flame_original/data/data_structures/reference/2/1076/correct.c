#include<stdio.h>
#include<string.h>
int a[100];//shu
char yun[100];//yunshuan
char s[100];
int len;
int sum = 0;
void fu0(char* s1, int len)
{
	int t = 0;
	while (t < len)
	{
		if (isdigit(s1[t]))
		{
			a[sum] = 10 * a[sum] + s1[t] - '0';
			t++;
		}
		else 
		{
			yun[sum] = s1[t];
			sum++;
			t++;
		}
	}
}
void yunsuan(int *a,int *b,char c)
{
	if (c == '*')
	{
		*a = *a * *b;
	}
	else if(c=='/')
	{
		*a=( * a) / (*b);
	}
	else if (c == '+')
	{
		*a = *a + *b;
	}
	else if (c == '-')
	{
		*a = *a - *b;
	}
}
void delte(int a[], char v[], int i)
{
	for (int j = i+2; j < sum; j++)
	{
		a[j - 1] = a[j];
	}
	for (int q = i + 1; q < sum; q++)
	{
		yun[q - 1] = yun[q];
	}
	sum = sum - 1;
}
int main()
{
	int i ,j;
	gets(s);
	for (i = j = 0; s[i] != '\0'; i++)
	{
		if (s[i] != ' ')
		{
			s[j++] = s[i];
		}
	}
	s[j] = '\0';
	len = strlen(s);
	fu0(s, len);
	i = 0;
	while( i < sum)
	{
		if (yun[i] == '*' || yun[i] == '/')
		{
			yunsuan(&a[i], &a[i + 1], yun[i]);
			delte(a, yun, i);
		}
		else
		{
			i++;
		}
	}
	for (int q1 = 1; q1 < sum; q1++)
	{
		yunsuan(&a[0], &a[q1], yun[q1-1]);
	}
	printf("%d", a[0]);
	return 0;
}
