#include <stdio.h>
#include <stdlib.h>

struct line{
	int x1;
	int y1;
	int x2;
	int y2;
	int num;
}ls[1000],tmp;

int cmp(struct line a,struct line b)
{
	if(a.x1==b.x1) return (a.y1-b.y1);
	else return (a.x1-b.x1);
}

void sort(int n)
{
	int i=0,j=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(ls[j].x1>ls[j+1].x1||(ls[j].x1==ls[j+1].x1&&ls[j].y1<ls[j+1].y2))
			{
				tmp=ls[j];
				ls[j]=ls[j+1];
				ls[j+1]=tmp;
				
			}
		}
	}
}

int main()
{
	int n,i,j,max=0,m=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d%d%d%d",&ls[i].x1,&ls[i].y1,&ls[i].x2,&ls[i].y2);
		ls[i].num=1;
	}
	sort(n);
//	qsort(ls,n,sizeof(struct line),cmp);
/*	for(i=0;i<n;i++)
	{
		printf("%d %d %d %d\n",ls[i].x1,ls[i].y1,ls[i].x2,ls[i].y2);
	}*/
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(ls[j].x1==ls[i].x2&&ls[j].y1==ls[i].y2)
			{
				ls[i].num++;
				ls[i].x2=ls[j].x2;
				ls[i].y2=ls[j].y2;
			}
		}
		if(ls[i].num>max)
		{
			m=i;
			max=ls[i].num;
		}
	}
	printf("%d %d %d\n",max,ls[m].x1,ls[m].y1);
	//printf("%d",ls[1].x1);
	return 0;
} 



