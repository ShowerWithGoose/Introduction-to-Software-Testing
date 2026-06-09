#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct polynomial{
	int coef,ex;
	struct polynomial *next;
}poly;
poly a[200],b[200],*p,*q,*first=NULL;
int insert(poly *front,int coef,int ex)
{
	poly *p;
	p=(poly*)malloc(sizeof(poly));
	p->coef=coef;
	p->ex=ex;
	p->next=NULL;
	if(first==NULL)
	first=p;
	else if(front==NULL)
	{
		p->next=first;
		first=p;
	}
	else
	{
		p->next=front->next;
		front->next=p;	
	}
	return 1;
}
int search(int coef,int ex)
{
	poly *p,*front=NULL;
	for(p=first;p!=NULL;front=p,p=p->next)
	{
		if(p->ex==ex)
		{
			p->coef+=coef;
			return 1;
		}
		else if(p->ex<ex)
		break;
	}
	return insert(front,coef,ex);
}
int main()
{
	int i,j,m,n;
	for(i=0;;i++){
	scanf("%d%d",&a[i].coef,&a[i].ex);
	if(getchar()=='\n')
	break;}
	m=i;
	for(i=0;;i++){
	scanf("%d%d",&b[i].coef,&b[i].ex);
	if(getchar()=='\n')
	break;}
	n=i;
	for(i=0;i<=m;i++) 
	for(j=0;j<=n;j++)
	search(a[i].coef*b[j].coef,a[i].ex+b[j].ex);
	for(p=first;p!=NULL;p=p->next)
	printf("%d %d ",p->coef,p->ex);
	return 0;
}

