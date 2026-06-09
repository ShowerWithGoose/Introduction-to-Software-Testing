#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
struct Node
{
	int coef;
	int expon;
	struct Node * Link;
};
typedef struct Node Poly;
typedef struct Node * pPoly;
void PrintPoly(pPoly p);
pPoly Find(int e,pPoly px);
pPoly MultPoly(pPoly px,pPoly p1,pPoly p2);
pPoly GetPoly(pPoly p);
void Attach(int c,int e,pPoly* prear);
int main()
{
	pPoly p1=(pPoly)malloc(sizeof(Poly)),p2=(pPoly)malloc(sizeof(Poly)),px=(pPoly)malloc(sizeof(Poly));
	p1->Link=NULL;
	p2->Link=NULL;
	px->Link=NULL;
	p1=GetPoly(p1);
	p2=GetPoly(p2);
	px=MultPoly(px,p1,p2);
	PrintPoly(px);
	return 0;
}
void Attach(int c,int e,pPoly* prear)
{
	pPoly p=(pPoly)malloc(sizeof(Poly));
	p->Link=NULL;
	p->coef=c;
	p->expon=e;
	(*prear)->Link=p;
	*prear=p;
	return;
}
pPoly GetPoly(pPoly p)
{
	pPoly rear=p;
	int c,e;
	char s[500]={};
	gets(s);
	char *ps=s;
	while(sscanf(ps,"%d%d",&c,&e)==2)
	{Attach(c,e,&rear);
	while(*ps!=' ') ps++;ps++;
	while(*ps!=' ') ps++;ps++;
    }
	pPoly cut=p;
	p=p->Link;
	free(cut);
	return p;
}
pPoly MultPoly(pPoly px,pPoly p1,pPoly p2)
{
	pPoly rear=px,p=p2,q=p1->Link;
	while(p!=NULL)
	{
		Attach((p1->coef)*(p->coef),(p1->expon)+(p->expon),&rear);
		p=p->Link;
	}
	while(q!=NULL)
	{
		p=p2;
		while(p!=NULL)
		{
			int c=(q->coef)*(p->coef);
			int e=(q->expon)+(p->expon);
			pPoly insert=Find(e,px);
			if(insert->Link!=NULL)
			{
				if(insert->Link->expon==e)
				{if(insert->Link->coef+c)
				insert->Link->coef=insert->Link->coef+c;
				else 
				{
					pPoly cut=insert->Link;
					insert->Link=cut->Link;
					free(cut);
				}
				}
				else
				{
				pPoly plus=(pPoly)malloc(sizeof(Poly));
			    plus->coef=c;plus->expon=e;
			    plus->Link=insert->Link;
			    insert->Link=plus;
				}
			}
			else
			Attach(c,e,&rear);
		p=p->Link;
		} 
	q=q->Link;
	}
	pPoly cut=px;
	px=px->Link;
	free(cut);
	return px;
}
pPoly Find(int e,pPoly px)
{
	pPoly p=px;
    while(p->Link!=NULL&&p->Link->expon>e)
    p=p->Link;
    return p;
}
void PrintPoly(pPoly p)
{
	while(p!=NULL)
	{
		printf("%d %d ",p->coef,p->expon);
		p=p->Link;
	}
	return;
}

