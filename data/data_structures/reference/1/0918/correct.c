#include<stdio.h>
#include<math.h>
int n;
int a[20]={0};
int used[20];
int true=1;
int false=0;
void dfs(int step);
int main()
{
	scanf("%d",&n);
	dfs(0);
	return 0;
}
void dfs(int step)
{
	int i;
	if(step==n)
	{
		for(i=0;i<n;i++)
		{
		printf("%d ",a[i]);	
		}
		printf("\n");
		return;
	}
	for(i=0;i<n;i++)
	{
		if(used[i]==0)
		{
		    a[step]=i+1;
			used[i]=true;
			dfs(step+1);
			used[i]=false;
		}
		
	}
}



