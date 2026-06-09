#include<stdio.h>
int s1[11],s2[11];
void pailie(int n,int x);
int main()
{
	int n,m,i,j,x;
	scanf("%d",&n);
	x=1;
	pailie(n,x);
	return 0;
}
void pailie(int n,int x)
{
	int i,j,k;
	if(x<=n)
	{
		for(i=1;i<=n;i++)
		{
			if(s2[i]==0)
			{
				s1[x]=i;
				s2[i]=1;
				pailie(n,x+1);
				s2[i]=0;
			}
		}
	}
	else if(x==n+1)
	{
		for(i=1;i<=n;i++)
		{
			printf("%d ",s1[i]);
		}
		printf("\n");
	}
}

