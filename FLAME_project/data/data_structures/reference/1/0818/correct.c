#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h> 

int N,A[11]={0},B[11]={0};
void dfs(int n)
{
	int i;
	if(n>N)
	{
		for(i=1;i<=N;i++)
		printf("%d%c",A[i],i==N?'\n':' ');
		return;
	}
	for(i=1;i<=N;i++)
		if(!B[i])
		{
			B[i]=1;
			A[n]=i;
			dfs(n+1);
			B[i]=0;
		}
}
int main()
{
	scanf("%d",&N);
	dfs(1);
	return 0;
}

