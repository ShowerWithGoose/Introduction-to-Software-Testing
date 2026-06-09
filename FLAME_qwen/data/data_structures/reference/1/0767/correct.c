#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void qpl(int l,int n,int a[],int had[]);
int main()
{
	int a[20]={0},had[20]={0};
	int n;
	scanf("%d",&n);
	qpl(0,n,a,had);
	return 0;
} 
void qpl(int l,int n,int a[],int had[])
{
	if(l==n)
	{
		for(int i=0;i<l;i++)
		printf("%d ",a[i]);
		printf("\n");	
	}
	for(int i=1;i<=n;i++)
	{
		if(had[i]==0)
		{
			a[l]=i;
			had[i]=1;
			qpl(l+1,n,a,had);
			had[i]=0;
		}
	}
}



