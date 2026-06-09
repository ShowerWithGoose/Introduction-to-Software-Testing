#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>


void arr(int* b, int m, int n);//排列 s为开头数字 e为结尾数字


int main()
{
	int k = 0;
	scanf("%d", &k);
	int b[12] = { 0 };


	//排列
	arr(b, 1, k);

	return 0;
}

int a[12] = { 0 }; //0未放入


void arr(int* b, int m, int n)
{
	

	if (m > n)//输出
	{
		for (int k = 1; k <= n; k++)
		{
			printf("%d ", b[k]);
		}
		printf("\n");
		return;
		
	}


	for (int i = 1; i <= n; i++)
	{
		if (a[i] == 0)
		{
			b[m] = i;
			a[i] = 1;
			arr(b, m + 1, n);
			a[i] = 0;
		}
	}
}
