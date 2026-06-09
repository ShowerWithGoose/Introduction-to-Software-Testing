#include<stdio.h>
#include<string.h>
#include<math.h>
int a[20],b[10];
int r[20];
void f(int,int);
int main()
{
    int m,k1;
	scanf("%d",&m);	
	for(k1=1;k1<=m;k1++)
	a[k1]=k1;
	f(m,1);
	return 0;
}
void f(int l,int l1)
{
	int j,k,t,p;
	if(l1==l+1)//需要输入l次，l1初始为1，所以l1=l+1时填满 
	{
		for(j=1;j<=l;j++)
		printf("%d ",b[j]);
		printf("\n");
		return;
	}
	for(t=1;t<=l;t++)
	{
		if(r[t]==0)
		{
			b[l1]=a[t];
		    r[t]=1;
		    f(l,l1+1);
		    r[t]=0;
		}
	}
	return;
}


