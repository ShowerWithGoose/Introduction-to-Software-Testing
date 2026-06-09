#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct multiple
{
	int an;
	int xn;
	struct multiple *pNext;	
}*Mul,mul;
void swap(Mul pa,Mul pc)
{
	int i=pc->an;
	pc->an=pa->an;
	pa->an=i;
	i=pc->xn;
	pc->xn=pa->xn;
	pa->xn=i;
}
int main()
{
	char c;
	int an=0,xn=0,i,flag;
	Mul pfirst1=(Mul)malloc(sizeof(mul)),p=pfirst1,pans;
	scanf("%d %d%c",&(p->an),&(p->xn),&c);
	if(c!='\n')
	{
		while(scanf("%d %d%c",&an,&xn,&c))
		{
			p->pNext=(Mul)malloc(sizeof(mul));
			p=p->pNext;
			p->an=an;
			p->xn=xn;
			if(c=='\n')
			{
				break;
			}
		}
	}
	p->pNext=NULL;
	Mul pfirst2=(Mul)malloc(sizeof(mul)),p2,pa,pb,pc;
	p=pfirst2;
	scanf("%d %d%c",&(p->an),&(p->xn),&c);
	if(c!='\n')
	{
		while(scanf("%d %d%c",&an,&xn,&c))
		{
			p->pNext=(Mul)malloc(sizeof(mul));
			p=p->pNext;
			p->an=an;
			p->xn=xn;
			if(c=='\n')
			{
				break;
			}
		}
	}
	p->pNext=NULL;
	p=(Mul)malloc(sizeof(mul));
	p->an=pfirst1->an*pfirst2->an;
	p->xn=pfirst1->xn+pfirst2->xn;
	p->pNext=NULL;
	pans=p;
	for(p=pfirst1;p!=NULL;p=p->pNext)
	{
		for(p2=pfirst2;p2!=NULL;p2=p2->pNext)
		{
			if(p==pfirst1&&p2==pfirst2)
			{
				continue; 
			}
			an=p->an*p2->an;
			xn=p->xn+p2->xn;
			for(pa=pans,pc=pa,flag=0;pa!=NULL;pc=pa,pa=pa->pNext)
			{
				if(xn==pa->xn)
				{
					pa->an+=an; 
					flag=1;
				}
			}
			if(flag==0)
			{
				pb=(Mul)malloc(sizeof(mul));
				pb->an=an;
				pb->xn=xn;
				pc->pNext=pb;
				pb->pNext=NULL;
			}
		}
	}
	for(pa=pans;pa->pNext!=NULL;pa=pa->pNext)
	{
		i=pa->xn;
		pc=NULL;
		for(pb=pa;pb!=NULL;pb=pb->pNext)
		{
			if(pb->xn>i)
			{
				pc=pb;
				i=pb->xn;
			}
		}
		if(pc!=NULL)
		{
			swap(pa,pc);
		}
	}
	for(pa=pans;pa!=NULL;pa=pa->pNext)
	{
		printf("%d %d ",pa->an,pa->xn);
	}	
	return 0;
} 













