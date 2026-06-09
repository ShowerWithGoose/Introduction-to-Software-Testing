#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct loca{
	int x1,y1;
	int x2,y2;
}situ[110];

struct ans{
	int x,y;
}bg[110];

int comp(const void*a,const void*b)
{
	struct loca*aa=(struct loca*)a;
	struct loca*bb=(struct loca*)b;
	return ((aa->x1)-(bb->x1));

}

int max[110];
int x,y;


int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d%d%d%d",&situ[i].x1,&situ[i].y1,&situ[i].x2,&situ[i].y2);
	}
	qsort(situ,n,sizeof(situ[0]),comp);
	int k=0;
	int flag=1;
	int start=0;
	for(int l=0;l<n-1;l++)
	{
		for(int j=l+1;j<n;j++)
		{
			k=j; 
			if(situ[l].x2==situ[j].x1&&situ[l].y2==situ[j].y1)
			{
				if(flag)
				{
					start=l;
					bg[start].x=situ[start].x1;
					bg[start].y=situ[start].y1; 
					l=j-1;
					flag=0;
					max[start]++;
					break;	
				}
				max[start]++;
				if(j==n-1)
				{
					l=start;
					flag=1;
				}
				else
					l=j-1;
				break;
			}
		}
		if(flag==0&&k==n-1)
		{
			flag=1;
			l=start;
		}
	}
	int cnt=0;
	int yt=0;
	for(int p=0;p<n;p++)
	{
		if(cnt<max[p])
		{
			cnt=max[p];
			yt=p;
		}
	}
	printf("%d %d %d",cnt+1,bg[yt].x,bg[yt].y);
	
	return 0;
 } 

