#include<stdio.h>
#include<stdlib.h>
struct node
{
	long long a;
	long long n;
	struct node *next,*prior;
}x[10000],y[10000];
int main()
{
	long long i=0,j=0,i1,j1,k=0,sym=0,m;
	char d;
	struct node *head,*p,*q,*t,*tmp;
	head=NULL,t=NULL;
	{
	while(1)
	{
		i++;
		scanf("%lld%lld",&x[i].a,&x[i].n);
		scanf("%c",&d);
		if(d=='\n') break;
	} 
	while(1) 
	{
		j++;
		scanf("%lld%lld",&y[j].a,&y[j].n);
		scanf("%c",&d);
		if(d=='\n') break;
	}//读入部分
	}
	//输入部分 
//	q->next=NULL;q->prior=NULL; 
	for(i1=1;i1<=i;i1++)
		for(j1=1;j1<=j;j1++)
		{
			p=(struct node*)malloc(sizeof(struct node));
			p->next=NULL;p->prior=NULL;
			p->a=x[i1].a*y[j1].a;p->n=x[i1].n+y[j1].n;
			if(head==NULL)
			{
				head=p;q=p;
			} 
			else
			{
				if(p->n>q->n)
				{
					tmp=q;
					while(p->n>q->n) 
					{	
						if(p->n>q->prior->n) q=q->prior,sym=1;
						else if(p->n==q->prior->n) 
						{
							q->prior->a+=p->a;break;
						}
						else
						{
							q->prior->next=p;
							p->prior=q->prior;
							q->prior=p;
							p->next=q;break;
						}
					}
					if(sym==1) q=tmp,sym=0;
				}
				else if(p->n<q->n)
				{
					q->next=p;p->prior=q;q=p;
				} 
				else if(p->n==q->n)
				{
					q->a+=p->a;
				} 
				 	
			}	
		}
		t=head;
		while(t!=NULL)
		{
			printf("%lld %lld ",t->a,t->n);
			t=t->next;
		}
}


