#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int pers[100];

 
int permutation(int *pers, int n, int cur)
{
	int i = 0, j = 0;
	if(cur == n)
	{
	for(i = 0; i < n; i++)
	printf("%d ", pers[i]);
	printf("\n");
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
 
 
int main()	{
	int n;
	scanf("%d", &n);

	permutation(pers, n, 0);
 
}

