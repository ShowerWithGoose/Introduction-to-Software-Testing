#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
int main()
{
	int n,i=0,j=0,x1[105],y1[105],x2[105],y2[105];
	int count[105],max=-1,flag=0;
	scanf("%d",&n);
	while(i<n)
	{
		scanf("%d%d%d%d",&x1[i],&y1[i],&x2[i],&y2[i]);
		i++;
	}
	for(i=0;i<n;i++)
	count[i]=1;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(x2[i]==x1[j]&&y2[i]==y1[j])
			{
				count[i]+=count[j];
				x2[i]=x2[j];y2[i]=y2[j];
			}
			if(x1[i]==x2[j]&&y1[i]==y2[j])
			{
				count[i]+=count[j];
				x1[i]=x1[j];y1[i]=y1[j];
			}
		}
		if(count[i]>max)//如果这一条连线上的线段数比最大值还要大，则令标记值==i 
		{
		flag=i;
		max=count[flag];
		}
	}
	printf("%d %d %d",max,x1[flag],y1[flag]);
	return 0;
}

