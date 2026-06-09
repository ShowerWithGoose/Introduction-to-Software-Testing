#include <stdio.h>

int lenn,len,x[100]={0},y[100]={0};
int main()
{
	int n,lix[100]={0},liy[100]={0};
	scanf("%d",&n);
	int ex,ey,i,j,k,ins=0;
	for(i=1;i<=n;i++)
	{
		scanf("%d%d%d%d",&x[2*i-1],&y[2*i-1],&x[2*i],&y[2*i]);
	}
	lenn=1;
	len=1;
	for(i=1;i<=n;i++)
	{
		lenn=1;
		j=1;
		lix[2*j-1]=x[2*i-1];
		liy[2*j-1]=y[2*i-1];
		lix[2*j]=x[2*i];
		liy[2*j]=y[2*i];
		for(j=1;j<=n;j++)
		{
			for(k=1;k<=n;k++)
			{
				if(lix[2*j]==x[2*k-1]&&liy[2*j]==y[2*k-1])
				{
					lix[2*j+1]=x[2*k-1];
					liy[2*j+1]=y[2*k-1];
					lix[2*j+2]=x[2*k];
					liy[2*j+2]=y[2*k];
					ins=1;
					lenn++;
					break;
				}
			}
			
		}
		if(lenn>len)
		{
			ex=lix[1];
			ey=liy[1];
			len=lenn;
		}
		
	}
	printf("%d %d %d",len,ex,ey);
	return 0;
}


