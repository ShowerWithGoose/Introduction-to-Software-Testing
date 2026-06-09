#include<stdio.h>
void ans(int,int);
int n;
int a[10][10]={1,2,3,4,5,6,7,8,9,10},b[10];
int main()
{
	scanf("%d",&n);
	ans(n,0);
	return 0;
}
void ans(int c,int k)
{
	int i,m,l;
	if(c==0)
	{
		for(i=0;i<n;i++)
		if(i!=n-1) printf("%d ",b[i] );
		else printf("%d\n",b[i]);
		return;
	}
	for(i=0;i<c;i++)
	{
	for(m=l=0;m<=c-1;l++)
		{
			if(l!=i)
			{
				a[k+1][m]=a[k][l];
				m++;
			}
		}
		b[k]=a[k][i];
		ans(c-1,k+1);
	}
	
}



