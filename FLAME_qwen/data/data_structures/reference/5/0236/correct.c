#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int a;
	int x;
	struct Node* link;
};
typedef struct Node node;
typedef struct Node* pnode;

pnode insert(pnode list, int m, int n)
{
	pnode p, q, r;
	r=(pnode)malloc(sizeof(node));
	r->a=m;
	r->x=n;
	r->link=NULL;
	if(list==NULL)
		return r;
	for(p=list; p!=NULL&&n<p->x;q=p, p=p->link);
	if(p==list)
	{
		r->link=p;
		return r;
	}
	else
	{
		q->link=r;
		r->link=p;
	}
	return list;
}

pnode dispose(pnode list, int m, int n)
{
	int flag=0;
	pnode p, r; 
	for(r=p=list; p!=NULL; r=p,p=p->link)
	{
		if(p->x==n)
		{
			p->a+=m;
			flag=1;
			break;
		}
	}
	if(flag==0)
	list=insert(list, m, n);
	return list;
} 



int main()
{
	int m, n;
	char l;
	pnode p, list1=NULL, list2=NULL, r, q;
	do
	{
		r=(pnode)malloc(sizeof(node));
		r->link=NULL;
		scanf("%d%d%c", &r->a, &r->x, &l);
		if(list1==NULL)
			list1=p=r;
		else
		{
			p->link=r;
			p=p->link;
		} 
	} while(l!='\n');
	do
	{
		q=(pnode)malloc(sizeof(node));
		scanf("%d%d%c", &q->a, &q->x, &l);
		for(p=list1; p!=NULL; p=p->link)
		{
			m=(q->a)*(p->a);
			n=(q->x)+(p->x);
			list2=dispose(list2, m, n);
		}
		
	}while(l!='\n');
	for(p=list2;p!=NULL;p=p->link)
	printf("%d %d ", p->a, p->x); 
}

