#include<stdio.h>
int a[1005],used[1005];
void dfs(int *a,int *used,int n,int depth)   //全排列递归函数 
{
	int i,j;
	if(depth==n+1)  //终止条件 
	{
		for(i=1;i<=n;i++)
		{
			printf("%d ",a[i]);  //输出a中的数字 
		}
		printf("\n");return;
	}
	for(i=1;i<=n;i++)
	{
		if(used[i]==0)  //判断该数字是否用过 
		{
			used[i]=1;  //使用过进行标记 
			a[depth]=i;//a在该深度的数为未使用过的数 
			dfs(a,used,n,depth+1);//下一个深度 
			used[i]=0;//回溯的时候一定要把上次使用过的数变为没有使用过 
		}
	}
}
int main()
{	
	int n;
	scanf("%d",&n);
	dfs(a,used,n,1);
	return 0;
}




