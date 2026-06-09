#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>


struct line
{
	int start_x;
	int start_y;
	int end_x;
	int end_y;
};


struct line arr[200] = { 0 };

int find(struct line* arr, int i, int n);

int main()
{
	int n = 0;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d %d %d %d", &arr[i].start_x, &arr[i].start_y, &arr[i].end_x, &arr[i].end_y);
	}

	int max_len = 0, max_i = 0;
	int flag = 0;
	for (int i = 0; i < n; i++)
	{
		int count = 1;
		flag = find(arr, i, n);
		while (flag)
		{
			count++;
			flag = find(arr, flag % 1000, n);
		}
		if (count > max_len)
		{
			max_len = count;
			max_i = i;
		}
	}

	printf("%d %d %d\n", max_len, arr[max_i].start_x, arr[max_i].start_y);

	return 0;
}

int find(struct line* arr, int i, int n)
{
	for (int j = 0; j < n; j++)
	{
		if (j != i)
		{
			if (arr[i].end_x == arr[j].start_x && arr[i].end_y == arr[j].start_y)
			{
				return 1000 + j;
			}
		}
	}

	return 0;
}
