#include <stdio.h>

void f(int *m,int *n,int N,int depth)
{
	int i;
	if(depth == N + 1)
	{
		for(i = 1;i <= N;i++)
			printf("%d ",m[i]);
		printf("\n");
		return;
	}
	for(i = 1;i <= N;i++)
	{
		if(n[i] == 0)
		{
			n[i] = 1;
			m[depth] = i;
			f(m,n,N,depth + 1);
			n[i] = 0;
		}
	}
}

int main()
{
	int N,i,m[100] = {0},n[100] = {0};
	scanf("%d",&N);
	f(m,n,N,1);
}

