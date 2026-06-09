#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

//小数点的位置
int find(char a[])
{
	int i;
	for (i = 0; a[i] != '.';)
		i++;
	return i;
}
//去小数点
void nodot(char s[])
{
	int i, j;
	for (i = j = 0; s[i] != '\0'; i++)
		if (s[i] != '.')
			s[j++] = s[i];
	s[j] = '\0';
}
//去前导零
int prezeros(char s[])
{
	int i, j = 0;
	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] == '0')
			j++;
		else
			break;
	}
	return j;
}
int main()
{
	char a[105];
	//读取字符串
	gets(a);
	if (a[0] != '-')
	{
		//字符个数n
		int n = strlen(a);
		//小数点的位置m
		int m = find(a);
		//去小数点
		nodot(a);
		//前导零j个
		int j = prezeros(a);
		//有效数位个数k
		int k = strlen(a) - j;
		//输出
		if (k == 1)
			printf("%c", a[j]);
		else
		{
			printf("%c.", a[j]);
			for (int i = j + 1; i < strlen(a); i++)
				printf("%c", a[i]);
		}

		printf("e%d", m + k - n);
	}
	else
	{
		a[0] = '0';
		int n = strlen(a);
		//小数点的位置m
		int m = find(a);
		//去小数点
		nodot(a);
		//前导零j个
		int j = prezeros(a);
		//有效数位个数k
		int k = strlen(a) - j;
		//输出
		if (k == 1)
			printf("-%c", a[j]);
		else
		{
			printf("-%c.", a[j]);
			for (int i = j + 1; i < strlen(a); i++)
				printf("%c", a[i]);
		}

		printf("e%d", m + k - n);
	}

	return 0;
}



