#include<stdio.h>
#include<stdlib.h>
#define N 3628800
int num[11];
int delta[11];//用以标志是否曾经出现过 
void func(int n,int num[],int i)
{
	int r;
	int m=1;
	if(i==n+1)
	{
		for(r=1;r<=n;r++)
			delta[r]=0;
		for(r=1;r<=n;r++)
			delta[num[r]]=1;
		for(r=1;r<=n;r++)
		{
			if(delta[r]==0)
			{
				m=0;
				break;
			}
		}
		if(m==1)
		{
			for(r=1;r<=n;r++)
				printf("%d ",num[r]);
			printf("\n");
			for(r=1;r<=n;r++)
				delta[r]=0;
		}
	}
	else
	{
		for(r=1;r<=n;r++)
		{
			num[i]=r;
			func(n,num,i+1);	
		}
	}
}
int main()
{
	int n,i=1;
	scanf("%d",&n);
	func(n,num,i);
	return 0;
}

