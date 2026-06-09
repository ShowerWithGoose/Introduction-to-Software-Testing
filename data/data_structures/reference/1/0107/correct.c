#include<stdio.h>
int n=0;//输入
int num[10]={0};//记录数字组合 
int used[10]={0};//记录数字是否使用过 
void mar(int k)//记录是第几个数字 
{
	if(k==n)
	{
		int m=0;
		for(m=0;m<k;m++)
		printf("%d ",num[m]);
		printf("\n");
		return ;
	}
	int i=1;
	for(i=1;i<=n;i++)
	{
		if(used[i]==0)	
		{
		num[k]=i;
		used[i]=1;
		mar(k+1);
		used[i]=0;
		}
	}
}
int main()
{
	scanf("%d",&n);
	mar(0);
	return 0;	
 } 

