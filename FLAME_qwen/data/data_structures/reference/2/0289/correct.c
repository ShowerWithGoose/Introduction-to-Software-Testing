#include<stdio.h>

int main()
{
	char input[200];

	int num[200] = { 0 };//把数字提取出来 
	char symbol[200] = { ' ' };//把运算符号提取出来
	int parts[200] = { 0 };//被 + 和 - 分割的部分 
	int iN = 0, iS = 0, iP = 0;//上述数组的角标 
	_Bool symbolState = 1;//true是加法，FALSE是减法
	int sum = 0; //总和 

	char* p = input;
	gets(input);

	if (*p != '-')//这是对第一个数的符号的判定 
	{
		symbol[0] = '+';
		iS++;
	}

	else
	{
		symbol[0] = '-';
		iS++;
		p++;
		symbolState = 0;
	}

	while (*p != '=')//把数字、字母分别放进两个数组里，舍去空格 
	{
		if ('0' <= *p && *p <= '9')
		{
			num[iN] = num[iN] * 10 + *p - 48;
		}

		else if (*p != ' ')
		{
			symbol[iS] = *p;
			iN++, iS++;
		}

		p++;

	}

	for (int i = 0; i < iS; i++)//计算乘除法，这部分我写的有点复杂了，用草纸按照步骤演算一次，或者一边调试一边看数组的值 
	{
		switch (symbol[i + 1])
		{
		case '+':
			if (symbolState == 1)
			{
				parts[iP] = num[i];
			}
			else
			{
				parts[iP] = -num[i];
			}
			symbolState = 1;
			iP++;
			break;
		case '-':
			if (symbolState == 1)
			{
				parts[iP] = num[i];
			}
			else
			{
				parts[iP] = -num[i];
			}
			symbolState = 0;
			iP++;
			break;
		case '*':
			num[i + 1] *= num[i];
			break;
		case '/':
			num[i + 1] = num[i] / num[i + 1];
			break;
		default:
			if (symbolState == 1)
			{
				parts[iP] = num[i];
			}
			else
			{
				parts[iP] = -num[i];
			}
			iP++;
			break;
		}
	}

	for (int i = 0; i < iP; i++)//最后再求和 
	{
		sum += parts[i];
	}

	printf("%d", sum);

	return 0;
}

