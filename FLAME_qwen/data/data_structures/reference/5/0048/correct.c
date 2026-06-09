#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 1000000

struct Result
{
	int coefficient[MAXSIZE];
	int power[MAXSIZE];
} result;

char arr1[MAXSIZE]; 
char arr2[MAXSIZE];
int data1[MAXSIZE];
int data2[MAXSIZE];

int main()
{
	int i, j, k = 0, l, p, q, r = 0, length1 = 0, length2 = 0, temp;
	
	gets(arr1);
	gets(arr2);

	while (1)
	{
		while (arr1[r] && (arr1[r] < '0' || arr1[r] > '9'))
		{
			r++;
		}
		if (arr1[r])
		{
			p = r;
			q = r + 1;
			data1[length1] = arr1[r] - '0';
			while (arr1[q] >= '0' && arr1[q] <= '9')
			{
				data1[length1] = 10 * data1[length1] + (arr1[q] - '0');
				q++;
			}
			r = q;
			length1++;
		}
		else
		{
			break;
		}
	}
	
	r = 0;
	while (1)
	{
		while (arr2[r] && (arr2[r] < '0' || arr2[r] > '9'))
		{
			r++;
		}
		if (arr2[r])
		{
			p = r;
			q = r + 1;
			data2[length2] = arr2[r] - '0';
			while (arr2[q] >= '0' && arr2[q] <= '9')
			{
				data2[length2] = 10 * data2[length2] + (arr2[q] - '0');
				q++;
			}
			r = q;
			length2++;
		}
		else
		{
			break;
		}
	}
	
	for (i = 0; i < length1; i = i + 2)  // 计算乘积 
	{
		for (j = 0; j < length2; j = j + 2)
		{
			result.coefficient[k] = data1[i] * data2[j];
			result.power[k] = data1[i + 1] + data2[j + 1];
			k++;
		}
	}
	
	for (i = 0; i < k; i++)  // 合并同类项 
	{
		int flag = 1;
		while (flag == 1)
		{
			flag = 0;
			for (j = i + 1; j < k; j++)
			{
				if (result.power[i] == result.power[j])
				{
					result.coefficient[i] += result.coefficient[j];
					for (l = j; l < k - 1; l++)
					{
						result.coefficient[l] = result.coefficient[l + 1];
						result.power[l] = result.power[l + 1];
					}
					k--;
					flag = 1;
					break;
				}
			}
		}
	}
	
	for (i = 0; i < k - 1; i++)  // 从大到小排序 
	{
		for (j = 0; j < k - i - 1; j++)
		{
			if (result.power[j] < result.power[j + 1])
			{
				temp = result.power[j];
				result.power[j] = result.power[j + 1];
				result.power[j + 1] = temp;
				temp = result.coefficient[j];
				result.coefficient[j] = result.coefficient[j + 1];
				result.coefficient[j + 1] = temp;
			}
		}
	}
	
	for (i = 0; i < k; i++)
	{
		if (result.coefficient[i] != 0)
		{
			printf ("%d %d ", result.coefficient[i], result.power[i]);
		}
	}
	return 0; 
}





