#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	char origin[105];
	gets(origin);
	int len = strlen(origin);
	char num[105];
	int point=-1, notzero,j=0,flag = 0;
	for (int i = 0; i < len; i++)//做两个事情，一个是把小数点找到，一个是录入数字
	{
		if (origin[i] == '.')point = i;
		 if (origin[i] != '0'&&origin[i]!='.'&&flag ==0)
		{
			 flag = 1;
			 notzero = i;
		}
		 if (flag == 1 && origin[i] != '.')
			 num[j++] = origin[i];
	}
	/*printf("%d\n", point - notzero>0?point-notzero-1:point-notzero);*/
	if (len == 1)printf("%ce0", origin[0]);
	else if (point == -1)
	{
		for (int k = 0; k < j; k++)
			printf("%c", num[k]);
		printf("e0");
	}
	else {
		int tmp = j - 1;
		while (num[tmp--] == '0');
		if (tmp == -1)
			printf("%ce%d", num[0], point - notzero > 0 ? point - notzero - 1 : point - notzero);
		else {
			int k = 1;
			printf("%c.", num[0]);
			while (k <= tmp + 1)
				printf("%c", num[k++]);
			printf("e%d", point - notzero > 0 ? point - notzero - 1 : point - notzero);
		}
	}
	return 0;
}
