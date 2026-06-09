/*
对一个序列进行全排列――对序列的子列进行全排列 
*/ 
#include <stdio.h>
int target[15]={0},clue[15]={0};
void give_out(int a[],int n)
{
	for(int i=1;i<n+1;i++)
	{
		if(i==n) printf("%d\n",a[i]);
		else printf("%d ",a[i]);
	}
}

void permute(int b[],int c[],int target_num,int head)
{
		if(head>target_num)
		give_out(b,target_num);
		//子序列来到了最后一位 比如1234 已经排好了第四位 最后调用的函数里head从第4+1开始 也就是排完了 此为递归结束条件 
		else
		{
			for(int i=1;i<target_num+1;i++)
			{
			if(c[i]==0)
			{
			b[head]=i;//子序列的第一个放什么元素 
			c[i]=1;//放好了 为了标记已放好数字i（即已使用过i） 用一个全为0的数组的第i项置1来说明 以后只能再放非1的c[i]了（即if里的执行条件） 
			permute(b,c,target_num,head+1);//对更短的（后退一位的）子序列进行全排列 
			c[i]=0;//回溯（？） 
			}
			}
		}
} 
 
int main()
{
	int n;
	scanf("%d",&n);
	permute(target,clue,n,1);
	return 0;
} 

