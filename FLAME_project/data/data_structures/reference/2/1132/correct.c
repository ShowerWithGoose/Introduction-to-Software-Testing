#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

char ch[1000] = { 0 };


void move(int, int); //位移函数

int sum(int, int, char);//运算结果

void insert(int, int);//插入字符串

int main()
{
	gets(ch);
	int a = 0, b = 0;//数字大小
	int a1 = 0, b1 = 0;//数字位数
	int tmp = 0;

	//去空格
	for (int i = 0; i < strlen(ch); i++)
	{
		if (ch[i] == ' ')
		{
			for (int j = i + 1; j < strlen(ch); j++)
			{
				ch[j - 1] = ch[j];
			}
			ch[strlen(ch) - 1] = 0;
			i--;
		}
	}


	//mul/div
	for (int i = 0; i < strlen(ch); i++)
	{
		if (ch[i] == '*'||ch[i]=='/')
		{
			//前一个数
			for (int j = i - 1; j >= 0 && ch[j] >= '0' && ch[j] <= '9'; j--)
			{
				a = a + (ch[j] - '0') * pow(10, a1);
				a1++;
			}
			//后一个数
			for (int j = i + 1; ch[j] != '=' && ch[j] >= '0' && ch[j] <= '9'; j++)
			{
				b = b * 10 + ch[j] - '0';
				b1++;
			}
			tmp = sum(a, b, ch[i]);
			move(a1 + b1 + 1, i - a1);
			insert(tmp, i - a1);
			a1 = b1 = a = b = 0;
			i = 0;
		}
	}

	tmp = 0;


	int count = 0;
	int arr[1000] = { 0 };
	//add/sub
	for (int i = 0; i < strlen(ch) - 1; i++)
	{
		if (ch[i] == '+')
		{
			int j = i + 1;
			while (ch[j] >= '0' && ch[j] <= '9')
			{
				arr[count] = arr[count] * 10 + ch[j] - '0';
				j++;
			}
			count++;
			i = j - 1;
		}
		else if (ch[i] == '-')
		{
			int j = i + 1;
			while (ch[j] >= '0' && ch[j] <= '9')
			{
				arr[count] = arr[count] * 10 + ch[j] - '0';
				j++;
			}
			arr[count] = 0 - arr[count];
			count++;
			i = j - 1;
		}
		else
		{
			int j = i;
			while (ch[j] >= '0' && ch[j] <= '9')
			{
				arr[count] = arr[count] * 10 + ch[j] - '0';
				j++;
			}
			count++;
			i = j - 1;
		}

	}

	for (int i = 0; i < count; i++)
	{
		tmp += arr[i];
	}



	printf("%d\n", tmp);

	return 0;
}


//位移函数
void move(int x, int p) //x为删除位数，p为删除字符串开始下标
{
	for (int i = p + x; i < strlen(ch); i++)
	{
		ch[i - x] = ch[i];
	}
	ch[strlen(ch) - x] = 0;//清除=之后字符
}

//运算结果
int sum(int a, int b, char c)
{
	int res = 0;
	if ('+' == c) res = a + b;
	else if ('-' == c) res = a - b;
	else if ('*' == c) res = a * b;
	else res = a / b;
	return res;
}


void insert(int s, int p) //s数值，p下标
{
	char c[100] = { 0 };
	sprintf(c,"%d",s);//转换
	int x = strlen(c);
	int end = strlen(ch) + x - 1;
	//后移
	for (int i = strlen(ch) + x - 1; i > p + x - 1; i--)
	{
		ch[i] = ch[i - x];
	}
	ch[end + 1] = 0;

	for (int i = 0; i < x; i++)
	{
		ch[p + i] = c[i];
	}
}
