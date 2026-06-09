#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>


int main()
{
	int n,x1[105],x2[105],y1[105],y2[105],i,j,p,k,num,max=0;
	int a=0,b=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d%d%d%d",&x1[i],&y1[i],&x2[i],&y2[i]);
	}
	for(i=1;i<=n;i++)
	{
		for(j=i+1;j<=n;j++)
		{
			if(x1[i]>x1[j])
			{
				p=x1[i];
				x1[i]=x1[j];
				x1[j]=p;
				
				p=x2[i];
				x2[i]=x2[j];
				x2[j]=p;
				
				p=y1[i];
				y1[i]=y1[j];
				y1[j]=p;
				
				p=y2[i];
				y2[i]=y2[j];
				y2[j]=p;
				
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		k=i;
		num=1;
		for(j=i+1;j<=n;j++)
		{
			if(x1[j]==x2[k]&&y1[j]==y2[k])
			{
				num++;
				k=j;
			}
		}
		if(num>max)
		{
			max=num;
			a=x1[i];
			b=y1[i];
		}
	} 
	printf("%d %d %d",max,a,b);
	
	return 0;
}

