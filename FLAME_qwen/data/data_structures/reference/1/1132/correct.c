#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>


void arr(int* a, int s, int e);//排列 s为开头数字 e为结尾数字


int main()
{
	int n = 0;
	scanf("%d", &n);
	int a[12] = { 0 };


	//排列
	arr(a, 1, n);

	return 0;
}

int f[12] = { 0 }; //0未放入


void arr(int* a, int s, int e)
{
	

	if (s > e)//输出
	{
		for (int k = 1; k <= e; k++)
		{
			printf("%d ", a[k]);
		}
		printf("\n");
		return;
		
	}


	for (int i = 1; i <= e; i++)
	{
		if (f[i] == 0)
		{
			a[s] = i;
			f[i] = 1;
			arr(a, s + 1, e);
			f[i] = 0;
		}
	}
}
