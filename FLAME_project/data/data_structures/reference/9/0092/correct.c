#include<stdio.h>
int main()
{
	int n,x1[100]={0},x2[100]={0},y1[100]={0},y2[100]={0};
	int l,max=0,i,j,temp,k;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d %d %d %d",&x1[i],&y1[i],&x2[i],&y2[i]);
	}
	for(i=0;i<n;i++)
	{
		for(j=n-1;j>i;j--)
		{
			if(x1[j]<x1[j-1])
			{
				temp=x1[j];
				x1[j]=x1[j-1];
				x1[j-1]=temp;
				temp=x2[j];
				x2[j]=x2[j-1];
				x2[j-1]=temp;
				temp=y1[j];
				y1[j]=y1[j-1];
				y1[j-1]=temp;
				temp=y2[j];
				y2[j]=y2[j-1];
				y2[j-1]=temp;
			}
		}
	}
	int x,y;
	for(i=0;i<n;i++)
	{
		l=1;
		k=i;
		for(j=i+1;j<n;j++)
		{
			if(x1[j]==x2[k]&&y1[j]==y2[k])
			{
				l++;
				k=j;
			}
		}
		if(l>max)
		{
			max=l;
			x=x1[i];
			y=y1[i];
		}
	}
	printf("%d %d %d",max,x,y);
	return 0;
	
}

