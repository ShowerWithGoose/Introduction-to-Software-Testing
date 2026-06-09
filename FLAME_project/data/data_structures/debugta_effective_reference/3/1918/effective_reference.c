#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	char chinput[105];
	gets(chinput);
	int len = strlen(chinput);
	char choutput[105];
	int point=-1, sum,j=0,flag = 0;
	for (int i = 0; i < len; i++)//做两个事情，一个是把小数点找到，一个是录入数字
	{
		if (chinput[i] == '.')point = i;
		 if (chinput[i] != '0'&&chinput[i]!='.'&&flag ==0)
		{
			 flag = 1;
			 sum = i;
		}
		 if (flag == 1 && chinput[i] != '.')
			 choutput[j++] = chinput[i];
	}
	/*printf("%d\n", point - notzero>0?point-notzero-1:point-notzero);*/
	if (len == 1)printf("%ce0", chinput[0]);
	else if (point == -1)
	{
		for (int k = 0; k < j; k++)
			printf("%c", choutput[k]);
		printf("e0");
	}
	else {
		int lenth = j - 1;
		while (choutput[lenth--] == '0');
		if (lenth == -1)
			printf("%ce%d", choutput[0], point - sum > 0 ? point - sum - 1 : point - sum);
		else {
			int k = 1;
			printf("%c.", choutput[0]);
			while (k <= lenth + 1)
				printf("%c", choutput[k++]);
			printf("e%d", point - sum > 0 ? point - sum - 1 : point - sum);
		}
	}
	return 0;
}
