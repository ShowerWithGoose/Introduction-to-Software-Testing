#include<stdio.h>//连续线段 正序排列做法 
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
typedef struct no_de
{
	int x1;
	int y1;
	int x2;
	int y2;
	int num;
}*Node;
struct no_de node[105];

int comp(const void *p1,const void *p2)
{
	Node c=(Node)p1;
	Node d=(Node)p2;
	if(c->x1!=d->x1)
	{
		return c->x1-d->x1;
	}
	else
	{
		return c->y1-d->y1;
	}
}

int main()
{
	int n;
	scanf("%d",&n);
	int i,j,k;
	for(i=0;i<n;i++)
	{
		scanf("%d%d%d%d",&node[i].x1,&node[i].y1,&node[i].x2,&node[i].y2);
		node[i].num=1;
	}
	qsort(node,n,sizeof(node[0]),comp);
	int max=-1;
	int c,d;
	for(i=0;i<n;i++)
	{
		k=i;
		for(j=i+1;j<n;j++)
		{
			if(node[k].x2==node[j].x1 && node[k].y2==node[j].y1)
			{
				node[i].num++;
				k=j;
			}
		}
		if(node[i].num>max)
		{
			max=node[i].num;
			c=node[i].x1;
			d=node[i].y1;
		}
	}
	printf("%d %d %d",max,c,d);
	return 0;
}

