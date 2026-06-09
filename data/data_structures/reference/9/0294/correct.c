#include <stdio.h>
#include <stdlib.h>
typedef struct line{
	int fx;
	int fy;
	int rx;
	int ry;
	struct line *pnext;
}Line,*LINE;

void swap(LINE l,LINE l3)
{
	int i=l->fx;
	l->fx=l3->fx;
	l3->fx=i;
	i=l->fy;
	l->fy=l3->fy;
	l3->fy=i;
	i=l->rx;
	l->rx=l3->rx;
	l3->rx=i;
	i=l->ry;
	l->ry=l3->ry;
	l3->ry=i;
}
 
int main()
{
	int i,j;
	scanf("%d",&i);
	LINE l,l2,l3,l4,lfirst=(LINE *)malloc(sizeof(Line));
	scanf("%d %d %d %d",&(lfirst->fx),&(lfirst->fy),&(lfirst->rx),&(lfirst->ry));
	lfirst->pnext=NULL;
	l2=lfirst;
	for(j=0;j<i-1;j++)
	{
		l=(LINE *)malloc(sizeof(Line));
		scanf("%d %d %d %d",&(l->fx),&(l->fy),&(l->rx),&(l->ry));
		l->pnext=NULL;
		l2->pnext=l;
		l2=l;
	}
	for(l=lfirst;l->pnext!=NULL;l=l->pnext)
	{
		l3=NULL;
		j=l->fx;
		for(l2=l;l2!=NULL;l2=l2->pnext)
		{
			if(j>l2->fx)
			{
				j=l2->fx;
				l3=l2;
			}
		}
		if(l3!=NULL)
		{
			swap(l,l3);
		}
	}
	for(l=lfirst,l4=l,j=0;l!=NULL;l=l->pnext)
	{
		i=1;
		l2=l3=l;
		while(l2!=NULL)
		{
			if(l3->rx==l2->fx&&l3->ry==l2->fy)
			{
				i++;
				l3=l2;
			}
			l2=l2->pnext;
		}
		if(i>j)
		{
			j=i;
			l4=l;
		}
	}
	printf("%d %d %d",j,l4->fx,l4->fy);
	return 0;
}

