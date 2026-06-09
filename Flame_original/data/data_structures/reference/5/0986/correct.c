# include <stdio.h>
# include <math.h>
# include <string.h>
# include<stdlib.h>
#include <ctype.h>
int count;
typedef struct node{
    int a;
	int n;
    struct node *next;
}X;
X *tmp,*C;
void multi(X *A,X *B)
{
    X *p,*q,*first=NULL,*tail,*r,*m;
    int a=0,n=0;
    p=A;
    q=B;
    while(p!=NULL)
    {
        while(q!=NULL)
        {
            a=p->a*q->a;
            n=p->n+q->n;
            r=(X*)malloc(sizeof(X));
            r->a=a;
            r->n=n;
            r->next=NULL;
            if(first==NULL)
            {
                first=tail=r;
            }
            else
            {
                tail->next=r;
                tail=tail->next;
            }
            count++;
            q=q->next;
        }
        p=p->next;
        q=B;
    }
    p=A;
    q=B;
    while(p!=NULL)
    {
    	m=p;
    	p=p->next;
    	free(m);
	}
	while(q!=NULL)
	{
		m=q;
		q=q->next;
		free(m);
	}
    tmp= first;
}
int cmp(X*a,X*b)
{
    return a->n>b->n?-1:1;
}
void row(X *tmp)
{
    X a[count];
	X *first,*p;
    for (int i=0;i<count;i++)
    {
        a[i]=*tmp;
        tmp=tmp->next;
    }
    qsort(a,count ,sizeof(X),cmp);
    p=(X*)malloc(sizeof(X));
    *p=a[0];
    first=p;
    for(int i=1;i<count;i++)
    {
        if(a[i].n!=a[i-1].n)
        {
            (p->next)=(X*)malloc(sizeof(X));
            (p->next)->n=a[i].n;
            p->next->a=a[i].a;
            p->next->next=NULL;
            p=p->next;
        }
        else
        {
            p->a+=a[i].a;
        }
    }
    C=first;
}
X* input( )
{
     X *first=NULL,*tail,*p;
    while(1)
    {
    	p=(X*)malloc(sizeof(X));
    	scanf("%d %d",&p->a,&p->n);
    	p->next=NULL;
        if(first==NULL)
        {
            first=tail=p;
        }
        else
        {
            tail->next=p;
            tail=tail->next;
        }
        if('\n'==getchar()) break;
    }
    return first;
}
int main()
{
    X *p,*A,*B,*m;
   A=input( );
   scanf("\n");
   B=input( );
   multi(A,B);
   row(tmp);
   p=C;
   while(p!=NULL)
   {
       printf("%d %d ",p->a,p->n);
       m=p;
       p=p->next;
       free(m);
   }
	return 0;
}


