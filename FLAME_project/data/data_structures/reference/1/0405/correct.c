#include <stdio.h>
int N;
int a[12];
int flag[12]={0};

void dfs(int box)
{
	int i,j;
	if(box==N+1)
		{
			for(j=1;j<=N;j++)
			{
				printf("%d ",a[j]);
			}
			printf("\n");
			return;
		}
	for(i=1;i<=N;i++)
	{
		if(flag[i]==0)
		{
			a[box]=i;
		    flag[i]=1;
		    dfs(box+1);
		    flag[i]=0;
		}
		
	}
}
int main()
{
	scanf("%d",&N);
	dfs(1);
	return 0;
}

