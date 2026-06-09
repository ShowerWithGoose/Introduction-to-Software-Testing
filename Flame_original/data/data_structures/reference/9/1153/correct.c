#include<stdio.h>
int n,i,j,sx,sy,tep,count;
int x1[105],x2[105],y1[105],y2[105],next[105];	

int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d%d%d%d",&x1[i],&y1[i],&x2[i],&y2[i]);
	
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(i==j)
				continue;
				
			else if(x2[i]==x1[j]&&y2[i]==y1[j])
				next[i]=j;
			
		}
	}
	for(i=1;i<=n;i++)
	{
		tep=1;
		sx=next[i];
		while(sx!=0)
		{
			tep++;
			sx=next[sx];
		}
		if(tep>count)
		{
			count=tep;
			sy=i;
		}
	}
			
	printf("%d %d %d",count,x1[sy],y1[sy]);
}


