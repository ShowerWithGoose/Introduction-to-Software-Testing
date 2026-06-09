#include<stdio.h>
int jie(int n)
{
	if(n==1)
	{
		return 1;
	}
	return n*jie(n-1);
}
int main()
{
	int n,i,j,k,b[11][1000][11],q,f,c[1000];
	scanf("%d",&n);
	b[1][1][1]=1;
	for(i=2;i<=n;i++)
	{
		for(j=1;j<=jie(i-1);j++)
		{
			for(k=1;k<=i;k++)
			{
				for(q=1;q<k;q++)
				{
					b[i][j*i-i+k][q]=b[i-1][j][q];
				}
				for(q=k;q<i;q++)
				{
					b[i][j*i-i+k][q+1]=b[i-1][j][q];
				}
				b[i][j*i-i+k][k]=i;
			}
		}
	}
	for(j=1;j<=jie(n);j++)
	{
		c[j]=0;
		for(k=1;k<=n;k++)
		{
			c[j]=c[j]*10+b[n][j][k];
		}
	}
		for(k=1;k<=jie(n);k++)
		{
			for(j=1;j<=jie(n)-k;j++)
			{
			if(c[j]<c[j+1])
			{
			}
			else
			{
				i=c[j];
				c[j]=c[j+1];
				c[j+1]=i;
				for(i=1;i<=n;i++)
				{
				f=b[n][j][i];
				b[n][j][i]=b[n][j+1][i];
				b[n][j+1][i]=f;
				}
			}
		    }
		}
		for(j=1;j<=jie(n);j++)
		{
			for(k=1;k<=n;k++)
			{
				printf("%d ",b[n][j][k]);
			}
			printf("\n");
		}
}

