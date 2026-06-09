#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct tree{
	int date;
	int height;
	struct tree *l,*r;
}TREE;
TREE *f;
TREE *ne(TREE *r,int shu,int lon);
void p(TREE *r);
int main()
{
	TREE *r=NULL;
	int n,shu,i,lon=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&shu);
		lon=0;
		r=ne(r,shu,lon);
	}
	p(r);
	return 0;
}
TREE *ne(TREE *r,int shu,int lon)
{
	lon=lon+1;
	if(r==NULL)
	{
		r=(TREE *)malloc(sizeof(TREE));
		r->date=shu;
		r->l=r->r=NULL;
		f=r;
		r->height=lon;
	}
	else if(shu<r->date)
	r->l=ne(r->l,shu,lon);
	else if(shu>=r->date)
	r->r=ne(r->r,shu,lon);
	return r;
}
void p(TREE *r)
{
	if(r)
	{
		if(!(r->l)&&!(r->r))
		{
			printf("%d %d\n",r->date,r->height);
		}
		p(r->l);
		p(r->r);
	}
}

