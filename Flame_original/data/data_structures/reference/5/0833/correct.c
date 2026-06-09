#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include<math.h>
typedef struct duoxs
{
	int xs,zs;
	struct duoxs *link;
}dx;
dx *da=NULL,*db=NULL,*dc=NULL;
void mul(dx*,dx*);
void search(int,int);
int main() {
int i,j,k;
dx *p,*q;
do{
	p=(dx*)malloc(sizeof(dx));
	scanf("%d%d",&(p->xs),&(p->zs));
	p->link=NULL;
	if(da==NULL)
	  da=q=p;
	else
	{
		q->link=p;
		q=q->link;
	}
}while(getchar()!='\n');

do{
	p=(dx*)malloc(sizeof(dx));
	scanf("%d%d",&(p->xs),&(p->zs));
	p->link=NULL;
	if(db==NULL)
	  db=q=p;
	else
	{
		q->link=p;
		q=q->link;
	}
}while(getchar()!='\n');
mul(da,db);
p=dc;
while(p!=NULL)
{
	printf("%d %d ",p->xs,p->zs);
	p=p->link;
}
return 0;
}

void mul(dx *a,dx *b)
{
	dx *p,*q;
	int x,z;
	for(p=a;p!=NULL;p=p->link)
	  for(q=b;q!=NULL;q=q->link)
	  {
	  	x=(p->xs)*(q->xs);
	  	z=(p->zs)+(q->zs);
	  	search(x,z);
	  }	  
	  return;
}

void search(int x,int z)
{
	dx *p=dc,*q;
	if(dc==NULL)
	{
	dc=q=(dx*)malloc(sizeof(dx));
    q->xs=x,q->zs=z,q->link=NULL;
    return;
	}
    while(1)
    {
    	if(p->zs==z)
    	{p->xs+=x;return;}
    	if(p->link==NULL||p->link->zs<z)
    	{
    		q=(dx*)malloc(sizeof(dx));
    		q->xs=x,q->zs=z;
    		q->link=p->link;
    		p->link=q;
    		return;
		}
		p=p->link;
	}

}


