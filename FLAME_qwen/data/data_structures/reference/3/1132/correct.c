#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

int main()
{
	char ch_in[200] = { 0 };
	char ch_out[200] = { 0 };
	scanf("%s", ch_in);

	int pt = 0;//小数点下标
	int pn = 0;//第一个非零数字下标
	int num = 0;//第一个非零数字
	int exp = 0;//指数

	int flag = 0;
	//小数点
	for (int i = 0; i < strlen(ch_in); i++)
	{
		if (ch_in[i] == '.') pt = i;
		if (ch_in[i] >= '1' && ch_in[i] <= '9' && flag == 0)
		{
			pn = i;
			num = ch_in[i] - '0';
			flag = 1;
		}
	}

	if (pt < pn)//小于一
	{
		exp = pn - pt;
	}
	else
	{
		exp = pt - pn - 1;
	}

	ch_out[0] = num + '0';
	ch_out[1] = '.';

	int j = 2;
	for (int i = pn + 1; i < strlen(ch_in); i++)
	{
		if (ch_in[i] == '.') continue;
		ch_out[j] = ch_in[i];
		j++;
	}
	if (j == 2)
	{
		ch_out[1] = 0;
		j = 1;
	}

	char tmp[10] = { 0 };
	ch_out[j] = 'e'; j++;
	if (pt < pn) ch_out[j] = '-';
	sprintf(tmp, "%d", exp);
	strcat(ch_out, tmp);
	printf("%s", ch_out);

	return 0;
}
