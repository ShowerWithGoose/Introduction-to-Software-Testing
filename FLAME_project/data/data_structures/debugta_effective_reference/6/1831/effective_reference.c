#include <stdio.h>
#include <stdlib.h>
typedef struct node {
	int n;
	struct node *llink;
	struct node *rlink;
} lnode,*linklist;
linklist tou,p,q;
int i=0;
void pop();
void push(int);
int main() {
		tou=(linklist)malloc(sizeof(lnode));
		tou->rlink=NULL;
		int n1,n2;
	while(1)
	{
		scanf("%d",&n1);
		if(n1==-1)
		break;
		if(n1==0)
		pop();
		if(n1==1)
		{scanf("%d",&n2);
		push(n2);
		}
	}	
	return 0;
}
void pop()
{
	if(p==tou)
	{printf("error ");
	return ;}
	printf("%d ",p->n);
	p=p->llink;
	q=p;
	i--;
}
void push(int a)
{
	if(i==100)
	{printf("error");
	return ;
	}
		p=(linklist)malloc(sizeof(lnode));
		p->n=a;
		if(tou->rlink==NULL)
			{tou->rlink=p;
			p->llink=tou;}
		else
			{q->rlink=p;
			p->llink=q;}
		q=p;
		i++;
}

