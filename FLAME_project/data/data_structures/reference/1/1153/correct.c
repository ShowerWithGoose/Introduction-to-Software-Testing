#include <stdio.h>
#include <stdlib.h>
int count;
void rear(int *arr,int a,int b)
{
	int i;
	int tmp = arr[b];
	for (i = b; i > a; i--)
		arr[i] = arr[i - 1];
	arr[a] = tmp;
}
 
void derear(int *arr, int a, int b)
{
	int i;
	int tmp = arr[a];
	for (i = a; i <b; i++)
		arr[i] = arr[i + 1];
	arr[b] = tmp;
}
 
void order(int *arr,int d,int N)
{
	int i;
	if (d>N)
	{
		for(i=0;i<=N;i++)
			printf("%d ", arr[i]);
		printf("\n");
		count++;
	}
	else
	{
		for (i=d;i<=N; i++)
		{
			rear(arr,d,i);
			order(arr,d + 1, N);
			derear(arr,d,i);
		}
	}
}
 
int main()
{
	int N;
	scanf("%d", &N);
	int *arr = (int *)malloc(N*sizeof(int));
	int i;
	for (i = 0; i < N; i++)
		arr[i] = i + 1;
	order(arr,0,N-1);
 
	free(arr);
	return 0;
}

