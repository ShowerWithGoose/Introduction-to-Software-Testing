#include<stdio.h>

int f[105][105],n,x[4][105];

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d%d%d",&x[0][i],&x[1][i],&x[2][i],&x[3][i]);
		for(int j=1;j<i;j++)
		{
			f[i][j]=(x[2][i]==x[0][j])&&(x[3][i]==x[1][j]);
			f[j][i]=(x[2][j]==x[0][i])&&(x[3][j]==x[1][i]);
		}
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++) 
				if(f[i][k]&&f[k][j]) f[i][j]=f[i][k]+f[k][j];
	int ans=0,p;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(f[i][j]>ans) 
			{
				ans=f[i][j];
				p=i;
			}
	printf("%d %d %d\n",ans+1,x[0][p],x[1][p]);
	return 0;
}

