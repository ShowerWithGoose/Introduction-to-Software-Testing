#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#include<stdlib.h>

int n;
int judge[10+3]={0},output[10];//output用于储存输出，judge用于判断该数是否被取过； 

void dfs(int i);//假设output数组为格子，则每次往格子里放入满足条件的数字并进入下一个格子 
int main()
{
	scanf("%d",&n);
	dfs(0);
	return 0;
}

void dfs(int i)
{
	if(i==n)//已经放到n+1个格子，超出范围，输出数组 
	{
		int j;
		for(j=0;j<n;j++)
		{
			printf("%d ",output[j]);
		}
		printf("\n");
		return; 
	}
	else//格子未满，搜 
	{
		int j;
		for(j=1;j<=n;j++)//数字范围1~n，从第一个开始，相当于从小到大 
		{
			if(judge[j]==0)//没有被取过
			{
				output[i]=j;//将它放入第i个格子中
				judge[j]=1;//取过，置为1
				dfs(i+1);//往下继续搜
				judge[j]=0;//往下搜完后再重置，不会影响往下搜的结果 
			}
		}
	}
}

