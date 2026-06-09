#include<stdio.h>
int a[100],book[100];
int dfs(int step,int *n)
{
	int i;
	if(step==*n+1)
	{
		for(i=1;i<=*n;i++)
			printf("%d ", a[i]);
		printf("\n");
		return 0;
	}
	for(i=1;i<=*n;i++)
	{
		if(book[i]==0)
		{
			a[step]=i;
			book[i]=1;
			dfs(step+1,n);
			book[i]=0;
		}
	}
	return 0;
}
int main()
{
	int n,*p;
	p=&n;
	scanf("%d", &n);
	dfs(1,p);
	return 0;
} 





