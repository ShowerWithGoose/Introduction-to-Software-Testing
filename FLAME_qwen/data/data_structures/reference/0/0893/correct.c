#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#define N 100

int main()
{
	char arr[N];
	gets(arr);
	int n=strlen(arr);
	int i;
	for (i = 0; i < n; i++)
	{
		if (arr[i] != '-')
		{
			printf("%c", arr[i]);
		}
		else
		{
			if (arr[i - 1] >= 'a' && arr[i + 1] <= 'z' && arr[i - 1] < arr[i + 1])
			{
				for (int j = 1; j < (arr[i + 1] - arr[i - 1]); j++)
				{
					printf("%c", arr[i - 1] + j);
				}
			}
			else if (arr[i - 1] >= 'A' && arr[i + 1] <= 'Z' && arr[i - 1] < arr[i + 1])
			{
				for (int j = 1; j < (arr[i + 1] - arr[i - 1]); j++)
				{
					printf("%c", arr[i - 1] + j);
				}
			}
			else if (arr[i - 1] >= '0' && arr[i + 1] <= '9' && arr[i - 1] < arr[i + 1])
			{
				for (int j = 1; j < (arr[i + 1] - arr[i - 1]); j++)
				{
					printf("%c", arr[i - 1] + j);
				}
			}
			else
			{
				printf("%c", arr[i]);
			}
		}
	}
	return 0;
}
