#include<stdio.h>
int main()
{int n,an[4][100],hash[100]={0},px,py,x,y,i,k,j,ans=-1;
scanf("%d",&n);
for(i=0;i<n;i++)
	{scanf("%d%d%d%d",&an[0][i],&an[1][i],&an[2][i],&an[3][i]);
	}
for(i=0;i<n-1;i++)
	{for(j=0;j<n-i-1;j++)
		if(an[0][j]>=an[0][j+1])
			{k=an[0][j+1];
			an[0][j+1]=an[0][j];
			an[0][j]=k;
			k=an[1][j+1];
			an[1][j+1]=an[1][j];
			an[1][j]=k;
			k=an[2][j+1];
			an[2][j+1]=an[2][j];
			an[2][j]=k;
			k=an[3][j+1];
			an[3][j+1]=an[3][j];
			an[3][j]=k;
			}
	}

for(i=0;i<n;i++)
	{if(hash[i]==0)
		{hash[i]=1;
		k=0;
		x=an[2][i];
		y=an[3][i];
		for(j=i+1;j<n;j++)
			{if(hash[j]==0&&x==an[0][j]&&y==an[1][j])
				{k++;
				x=an[2][j];
				y=an[3][j];
				hash[j]=1;
				}
			}
		if(k>ans)
			{ans=k;
			px=an[0][i];
			py=an[1][i];
			}
		}
	}
printf("%d %d %d",ans+1,px,py);
return 0;
}

