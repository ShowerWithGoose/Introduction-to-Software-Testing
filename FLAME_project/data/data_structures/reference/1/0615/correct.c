#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h> 
int num[20]={0};
int gd[20]={0};
void A(int num[],int gd[],int n,int N)
{
	int j;
	if(n>=N)
	{
		for(j=0;j<N-1;j++)
			printf("%d ",num[j]);
		printf("%d\n",num[j]);
	}
	else
	{
		for(j=0;j<N;j++)
		{
			if(0==gd[j])
			{
				gd[j]=1;
				num[n]=j+1;
				A(num,gd,n+1,N);
				gd[j]=0;
			}
		}
	}
}
int main()
{
	int N,i=0;
	scanf("%d",&N);
	for(i=0;i<N;i++)
	{
		gd[i]=0;
	}
	A(num,gd,0,N);
	return 0;
}

