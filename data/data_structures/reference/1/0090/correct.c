#include <stdio.h>
void print(int n1[], int N)	//输出一行排列 
{
	int i;
	for(i = 0; i < N - 1; i++)
		printf("%d ", n1[i]);
	printf("%d\n", n1[i]);
}
int main()
{
	int i, j, k, N, N_jiecheng[10] = {1}, n1[10], p, tmp;
	scanf("%d", &N);
	for(i = 1; i < N; i++)	//计算N的阶乘 
		N_jiecheng[i] = N_jiecheng[i-1] * (i+1);
	for(i = 0; i < N; i++)	//求初始排列 
		n1[i] = i+1;
	print(n1, N);
	for(i = 1; i < N_jiecheng[N-1]; i++)	//依次寻找并输出每行排列 
	{
		for(j = N-2; j >= 0; j--)
			if(n1[j] < n1[j+1])
			{
				for(k = j+1, p = j+1; k < N; k++)
					if(n1[k] > n1[j] && n1[k] <= n1[p])
						p = k;
				tmp = n1[p];
				n1[p] = n1[j];
				n1[j] = tmp;
				break;
			}
		for(k = j+1; k <(j+N+1)/2; k++)
		{
			tmp = n1[N-k+j];
			n1[N-k+j] = n1[k];
			n1[k] = tmp;
		}
	print(n1, N);
	}
	return 0;
}

