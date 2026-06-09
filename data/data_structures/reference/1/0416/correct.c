#include<stdio.h>

void DFP(int *m,int *flag,int num,int depth);

int main()
{
	int num,i=0;
	int m[10000]={0},flag[10000]={0};
	scanf("%d",&num);
	DFP(m,flag,num,1);
	
	return 0;
} 

void DFP(int *m,int *flag,int num,int depth)
{
	int i=0;
	if(depth==(num+1))
	{
		for(i=1;i<=num;i++)
		{
			printf("%d ",m[i]);
		}
		printf("\n");
		return;
	}
	
	for(i=1;i<=num;i++)
	{
		if(flag[i]==0)
		{
			m[depth]=i;
			flag[i]=1;  //已经使用过了 
			DFP(m,flag,num,depth+1);
			flag[i]=0;  //回溯为下一次清零 
		 } 
	}
}



