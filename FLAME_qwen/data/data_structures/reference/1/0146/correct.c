#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
int a[11];
int flag[11];
void dfs(int n,int temp);

int main()
{
	int N;
	scanf("%d",&N);
	
	dfs(N,1);
	return 0;
}

void dfs(int n,int temp)
{
	int i=0,k=0,j;
	//记录第i张还在不在手里 ，在：0，不在 ：1 
    //temp是盒子数 

    
	if(temp==n+1)//遇到大于n的盒子，输出，全排列结束 
	{
		
		for(k=1;k<=n;k++)
		{
			printf("%d ",a[k]);
		}
		printf("\n");
		return;//打印完一种可能后返回最近的void 
	}
	
	for(i=1;i<=n;i++)//将现有的牌按照从小到大依次尝试放入第temp个盒子里
	{
		if(flag[i]==0)
		{
			a[temp]=i;
			flag[i]=1;
			dfs(n,temp+1);//考虑下一个盒子 
			flag[i]=0;//将牌取回，在考虑可能的下一种情况 
		}
	 } 
	
	return;// 所有可能结束，返回最后一种可能的viod（n，1），结束 
}

