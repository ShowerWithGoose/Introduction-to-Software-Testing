#include <stdio.h>
#include <stdlib.h>
void rearr(int *arr,int a,int b)
{
	int i;
	int tmp = arr[b];
	for (i = b; i > a; i--)
		arr[i] = arr[i - 1];
	arr[a] = tmp;
}
 
void derearr(int *arr, int a, int b)
{
	int i;
	int tmp = arr[a];
	for (i = a; i <b; i++)
		arr[i] = arr[i + 1];
	arr[b] = tmp;
}
 
void perm(int *arr,int d,int N)
{
	int i;
	if (d > N)
	{
		for (i = 0; i <= N; i++)
			printf("%d ", arr[i]);
		printf("\n");
	}
	else
	{
		for (i = d; i <= N; i++)
		{
			rearr(arr,d,i);
			perm(arr,d + 1, N);
			derearr(arr,d,i);
		}
	}
}
 
int main()
{
    int arr[20];
	int N;
	scanf("%d", &N);
	
	int i;
	for (i = 0; i < N; i++)
		arr[i] = i + 1;
	perm(arr,0,N-1);
 
	return 0;
}
