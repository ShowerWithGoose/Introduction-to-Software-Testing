#include <stdio.h>
#include <stdlib.h>

typedef struct num{
	int co;
	int ex;
	struct num *link;
}num;
num *linka,*linkb,*linkc,*heada=NULL,*headb=NULL,*headc=NULL,*p,*r,*q;
int main(int argc, char *argv[]) {
	char c;
	int i=0,value;
	int m,n;
	int j=0;
    while(1)
{
linka=(num*)malloc(sizeof(num));
linka->link=NULL;
scanf("%d %d",&linka->co,&linka->ex);
if(heada==NULL)
heada=linka;
else
p->link=linka;
p=linka;
c=getchar();
if(c=='\n')
break;
}
linkb=(num*)malloc(sizeof(num));
linkb->link=NULL;
headb=linkb;
scanf("%d %d",&linkb->co,&linkb->ex);
p=linkb;
linkb=(num*)malloc(sizeof(num));
linkb->link=NULL;
while(scanf("%d %d",&linkb->co,&linkb->ex)!=EOF)
{p->link=linkb;
p=linkb;
linkb=(num*)malloc(sizeof(num));
linkb->link=NULL;
c=getchar();
if(c=='\n')
break;
}
linka=heada;
linkb=headb;

while(linka!=NULL)
{
while(linkb!=NULL)
{linkc=(num*)malloc(sizeof(num));
i++;
linkc->link=NULL;
linkc->co=linka->co*linkb->co;
linkc->ex=linka->ex+linkb->ex;
if(headc==NULL)
headc=linkc;
else
p->link=linkc;
p=linkc;
linkb=linkb->link;
}
linkb=headb;
linka=linka->link;
}
r=headc;
q=r->link;
value=i;
for(i=0;i<value-1;i++)
{
	for(j=0;j<value-1-i;j++)
	{
	if(r->ex==q->ex)
	{r->co=r->co+q->co;
	r->link=q->link;
	q=r->link;
	}
	else 
	{
	if(r->ex<q->ex)
	{
	m=r->co;
	n=r->ex;
	r->co=q->co;
	r->ex=q->ex;
	q->co=m;
	q->ex=n;
	}
	r=q;
	q=r->link;
    }
	}
	r=headc;
	q=r->link;
}

linkc=headc;
while(linkc!=NULL)
{printf("%d %d ",linkc->co,linkc->ex);
linkc=linkc->link;
}
	return 0;
}

