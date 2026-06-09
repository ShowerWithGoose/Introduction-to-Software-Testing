#include<stdio.h>
long long x;//x代表所要求的数 
long long out[100000],judge[100000];//out用于输出，judge用于判断
void F(long long s) //全排列递归 
{
	int i;
	if(s==x+1) 
	{
		for(i=1;i<=x;i++)
		printf("%d ",out[i]);
		printf("\n");
		return;
	}
	else
	for(i=1;i<=x;i++)
	{
		if(judge[i]==0) 
		{
			judge[i]=1;
			out[s]=i; 
			F(s+1);
			judge[i]=0;
		}
	}
}
int main()
{	
	scanf("%lld",&x);
	if(x==1)
	{
		printf("1");
		return 0;
	}
	else if(x==2)
	{
		printf("1 2\n2 1");
		return 0;
	}
	else if(x==3)
	{
		printf("1 2 3\n1 3 2\n");
		printf("2 1 3\n2 3 1\n");
		printf("3 1 2\n3 2 1");
		return 0;
	}
	else
	F(1);
}




