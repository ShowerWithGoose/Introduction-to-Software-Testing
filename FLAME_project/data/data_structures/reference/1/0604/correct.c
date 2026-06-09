#include<stdio.h>


int s[11];
void pailie(int m,int n) 
{
	int i,j,k;

	if(m==n)
	{
		for(i=1;i<=m;i++)
		{
			printf("%d ",s[i]);
		}
		printf("\n");
		return;
	}
	else 
	{
		for(j=1;j<=m;j++)
		{
			int fl=1;
			for(k=1;k<=n;k++)
			{
				
				if(s[k]==j)
				fl=0;
			}
			if(fl)
			{
				s[n+1]=j;
				pailie(m,n+1);
			}
		}
	}
}
int main()
{
	int n,i;
	
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
	
		s[i]=i+1;
	}

	pailie(n,0);

}


