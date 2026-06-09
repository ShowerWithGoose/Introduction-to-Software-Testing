#include <stdio.h>

void Swap(int *a, int *b)
{
	int t = *a;
 
	*a = *b;
	*b = t;
}

void bubbleSort(int a[], int n)   // n个数 ， 0 ~ n-1 
{
	int i, j, hold, flag;
	for (i = 0; i < n-1; i++)
	{
		flag = 0;
		for (j = 0; j < n-1-i; j++)
		{
			if (a[j] > a[j + 1])
			{
				hold = a[j];
				a[j] = a[j + 1];
				a[j + 1] = hold;
				flag = 1;
			}
		}
		if (0 == flag)
		break;
	}
}

int temp[10000];
int j;

void FullPermutation(int source[], int begin, int end)
{
	int i;
 
	if (begin >= end) // 找到一个排列
	{
		for (i = 0; i < end; i++)
		{
			temp[j]=temp[j]*10+source[i];
		}
		j++;
	}
	else// 没有找完一个排列，则继续往下找下一个元素
	{
		for (i = begin; i < end; i++)
		{
			if (begin != i)
			{
				Swap(&source[begin], &source[i]); // 交换
			}
 
			// 递归排列剩余的从begin+1到end的元素
			FullPermutation(source, begin + 1, end);
 
			if (begin != i)
			{
				Swap(&source[begin], &source[i]); // 回溯时还原
			} 
		}
	}
}
 
int main()
{
	int source[30];
	int i, count, sss, ttt, qqq;
 
	scanf("%d", &count);
 
	// 初始化数组
	for (i = 0; i < count; i++)
	{
		source[i] = i + 1;
	}
 
	FullPermutation(source, 0, count);
	
	bubbleSort(temp , j);
	
	for(i=0;i<10;i++)
	{
		sss=sss+i;
	 } 
	
	int a[10],k;
	for(i=0;i<j;i++)
	{
		for(k=1;k<=count;k++)
		{
			a[count-k]=temp[i] % 10;
			temp[i]=temp[i]/10;
		}
		for(k=0;k<count;k++)
		{
			printf("%d ",a[k]);
		}
		printf("\n");
	}
 
	return 0;
}


