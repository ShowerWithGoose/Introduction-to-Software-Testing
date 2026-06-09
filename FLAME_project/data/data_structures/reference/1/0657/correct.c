#include<stdio.h>
#define N 10
int mark[N]={0},arr[N+1];
void rank(int,int);
int main()
{
	int n;
	scanf("%d",&n);
	rank(0,n);
	return 0;
}
void rank(int loca,int rest)
{
	int i,max=rest+loca;
	if(0==rest)
	{
		for(i=0;i<max;i++)
		{
			printf("%d ",arr[i]);
		}
		printf("\n");
	}
	else
	{
		for(i=0;i<max;i++)
		{
			if(0==mark[i])
			{
				arr[loca]=i+1;
				mark[i]=1;
				rank(loca+1,rest-1);
				mark[i]=0;
			}
		}
	}
}




