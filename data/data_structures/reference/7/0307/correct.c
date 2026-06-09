#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

typedef struct a
{
	int a,b; 
	struct a *l,*r;
}poi;

void buildtree(poi** point,poi* n)
{
	if((*point)==NULL)
	{
		*point=n;
		(*point)->b=1;
	}
	else if(n->a>=(*point)->a)
	{
		if((*point)->r==NULL)
		{
			(*point)->r=n;
			n->b=(*point)->b+1;
		}
		else
		{
			buildtree(&((*point)->r),n);
		}
	}
	else
	{
		if((*point)->l==NULL)
		{
			(*point)->l=n;
			n->b=(*point)->b+1;
		}
		else
		{
			buildtree(&((*point)->l),n);
		}
	}
}

void read(poi* point)
{
	if(point==NULL)
	return;
	else if(point->l==NULL&&point->r==NULL)
	{
		printf("%d %d\n",point->a,point->b);
	}
	else
	{
		if(point->l!=NULL)
		{
			read(point->l);
		}
		if(point->r!=NULL)
		{
			read(point->r);
		}
	}
}

int main()
{
	poi *n,*h=NULL;
	int x,y,i;
	scanf("%d",&y);
	for(i=0;i<y;i++)
	{
		scanf("%d",&x);
		n=(poi*)malloc(sizeof(poi));
		n->a=x;
		n->l=n->r=NULL;
		buildtree(&h,n);
	}
	read(h);
	return 0;
}

