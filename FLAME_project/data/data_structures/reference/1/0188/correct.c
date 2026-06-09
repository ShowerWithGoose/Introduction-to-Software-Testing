#include<stdio.h>
int num; 
int chuan[12]={0},use[12]={0};
int out(int,int);
int main()
{
	scanf("%d",&num);
	int i=1;
	for(;i<=num;i++)
	{
		out(i,1);
	}
	return 0;
}
int out(int a,int wei)
{
	use[a]=1;
	chuan[wei]=a;
	if(wei==num)
	{
		int i=1;
		for(;i<=num;i++)
		{
			printf("%d ",chuan[i]);
		}
		printf("\n");
	}
	else
	{
		int i=1;
		for(;i<=num;i++)
		{
			if(use[i]==0) out(i,wei+1);
		}
	}
	
	use[a]=0;
}

