#include<stdio.h>
#include<stdlib.h>
struct lines{
	int x1,y1;
	int x2,y2;
	int flag;
}line[108];
int count[108],x[108],y[108];
int cmp(const void*a,const void*b)
{
	int t1=((struct lines*)a)->x1;
	int t2=((struct lines*)b)->x1;
	if(t1>t2)
	return 1;
	else
	return -1;
}
int main()
{
	int n;
	scanf("%d",&n);
	int i;
	for(i=0;i<n;i++)
	{
		scanf("%d%d%d%d",&line[i].x1,&line[i].y1,&line[i].x2,&line[i].y2);
		line[i].flag=0;
	}
	qsort(line,n,sizeof(struct lines),cmp);
	int j=0,k=0,bx,by;
	for(i=0;i<n;i++)
	{
		if(line[i].flag==1)
		continue;
		else
		{
			count[k]=1;
			line[i].flag=1;
			x[k]=line[i].x1;
			y[k]=line[i].y1;
			bx=line[i].x2;
			by=line[i].y2;
		}
		for(j=i+1;j<n;j++)
		{
			if((bx==line[j].x1)&&(by==line[j].y1)&&line[j].flag==0)
			{
				count[k]++;
				line[i].flag=1;
				bx=line[j].x2;
				by=line[j].y2;
			}
		}
		k++;
	}
	int max=0,maxi;
	for(i=0;i<k;i++)
	{
		if(count[i]>max)
		{
			max=count[i];
			maxi=i;
		}
	}
	printf("%d %d %d",max,x[maxi],y[maxi]);
	return 0;
} 

