#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
typedef struct coor{
	int x1;
	int y1;
	int x2;
	int y2;
	struct coor *link;
}Coor,*LinkList;

int cmp(const void *a,const void *b)
{
	struct coor *c=(struct coor *)a;
	struct coor *d=(struct coor *)b;
	if(c->x1!=d->x1)
		return c->x1-d->x1;
	else
		return c->y1-d->y1;
}
int main()
{
	Coor m[100];
	int n,i,j=0,max=1,l=1;
	LinkList p=NULL;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d%d%d%d",&m[i].x1,&m[i].y1,&m[i].x2,&m[i].y2);
		m[i].link=NULL;
	}
	qsort(m,n,sizeof(m[0]),cmp);
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(m[i].x2==m[j].x1&&m[i].y2==m[j].y1)
			{
				m[i].link=&m[j];
				break;
			}
		}
	}
	for(i=0;i<n;i++)
	{
		p=m[i].link;
		while(p!=NULL)
		{
			l++;
			p=p->link;
		}
		if(l>=max)
		{
			max=l;
			j=i;
		}
		l=1;
	}
	printf("%d %d %d",max,m[j].x1,m[j].y1);
 	return 0;
}


