#include<stdio.h>
void f(int *a,int t,int n);
int n,a[15],j,t,k,sign;
int main()
{
	scanf("%d",&n);
	f(a,1,n);
	return 0;
}
void f(int *a,int t,int n)
{
	int i;
	for(i=1;i<=n;i++)
	{
		sign=0;
		for(j=1;j<t;j++)
		{
			if(i==a[j]) sign=1;    //是否和前面重复 
		}
		if(sign==0)                    //不重复则递归下一层 
		{
			a[t]=i;
			if(t==n	)
			{
				for(k=1;k<=n;k++)
				{
					printf("%d ",a[k]);
				}
				printf("\n");
			}
			if(t<n) f(a,t+1,n); 
		}
	}
}



