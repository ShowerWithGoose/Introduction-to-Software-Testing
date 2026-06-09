#include <stdio.h>

int num[10]={0};
int t,N;

void prt(int N)
{
	int i;
	for(i=0;i<N;i++)
	{
		printf("%d ",num[i]);
	}
	printf("\n");
}

void sort(int n)
{
	int i,j;
	if(n==0)
	{
		prt(N);
		return;
	}
	for(i=1;i<=N;i++)
	{
		for(j=0;j<N-n-1;j++)
		{
			if(i==num[j]) break;
		}
		if(i==num[j]) continue;
		num[N-n]=i;
		sort(n-1);
	}
}

int main()
{
	scanf("%d",&N);
	sort(N);
	return 0;
}

