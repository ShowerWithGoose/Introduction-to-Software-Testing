#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void print(int *pers, int n)
{
	int i =0;
	for(i = 0; i < n; i++)
	{
		printf("%d%c", pers[i],i!=(n-1)?' ':'\n');
	}
	//printf("\n");
}
/*
 *pers保存已经排列的数，cur标记当前pers中的排列位置
 * */
 
int permutation(int *pers, int n, int cur)
{
	int i = 0, j = 0;
	if(cur == n)
	{
		print(pers, n);
	}
	else
	{
		for(i = 1; i <= n; i++)   //每次都是1~n取数，已有数的排除通过内循环剔除
		{
			int ok = 1;
			for(j = 0; j < cur; j++)   //遍历已取数
			{
				if(pers[j] == i)
				{
					ok = 0;
					break;
				}
			}		
			if(ok)
			{
				pers[cur] = i;
				permutation(pers, n, cur + 1);
			}	
		}
	}
}
 
 
void main()
{
	int n;
	scanf("%d", &n);
	int *pers = (int *)malloc(n * sizeof(int));		
	permutation(pers, n, 0);
 
}



