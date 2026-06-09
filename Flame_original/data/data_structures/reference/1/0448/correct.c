#include<stdio.h>
#include<stdlib.h>
void P(int a,int b,int sz[],int t[]);
int main()
{
	int n;
	int sz[15],t[15];
	int i;
	scanf("%d",&n);
	for(i=0;i<=n;i++)
	{
		t[i]=0;
	}
	P(0,n,sz,t);
	return 0;
}
void P(int a,int b,int sz[],int t[]) 
{
	int i;
	if(a>=b)
	{
		for(i=0;i<b-1;i++)
			printf("%d ",sz[i]);
		printf("%d\n",sz[i]);
	}
	else
	{
		for(i=0;i<b;i++)
		{
			if(t[i]==0)
			{
				t[i]=1;
				sz[a]=i+1;
				P(a+1,b,sz,t);
				t[i]=0;
			}
		}
	}
}

