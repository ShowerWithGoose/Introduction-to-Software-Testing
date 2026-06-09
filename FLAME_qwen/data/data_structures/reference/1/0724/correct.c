#include<stdio.h>
int list[15]; //打印列表 
int flag[15];
void dfs_backtrack(int depth, int num_total);
int main(void)
{
	int n;
	scanf("%d",&n);
	dfs_backtrack(1,n);
	return 0;
}

void dfs_backtrack(int depth, int num_total)
{
	if(depth==num_total+1)
	{
		for(int i=1;i<=num_total;i++)
		{
			printf("%d ",list[i]);
		}
		printf("\n"); 
	}
	else
	{
		for(int i=1;i<=num_total;i++) //遍历 
		{
			if(flag[i]==0)//判断目前的这个数是不是之前没有用过 
			{
				flag[i]=1; //这个数现在标记为用过 
				list[depth]=i; //这一层的打印列表的数组中的值选定了
				dfs_backtrack(depth+1,num_total); //继续深度搜索
				flag[i]=0; //再深搜完回溯的时候程序会运行到这个地方，此时需要把原先标记过的数取消标记，
				//否则无法进行后续搜索 
			}	
		} 
	}
}

