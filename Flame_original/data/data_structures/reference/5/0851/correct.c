#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

#define ep 1e-6
#define pi 3.14159265
#define pf printf
#define sf scanf
#define ll long long
#define ull unsigned long long
#define NumberOf(x) (sizeof(x)/sizeof(x[0])
#define max(A,B) ((A)>(B)?(A):(B))

struct link{
	int a;
	int n;
	struct link *next;
};
int main()
{
	struct link *first1=NULL,*first2=NULL,*first=NULL,*p1=NULL,*p2=NULL,*p=NULL,*q;
	int i,j,N1,N2,N,temp;
	char c=0;
	for(i=0;c!='\n';i++)
	{
		q=(struct link *)malloc(sizeof(struct link));
		sf("%d%d",&(q->a),&(q->n));
		if(first1==NULL)
		{
			first1=p1=q;
		}
		else
		{
			p1->next=q;
			p1=p1->next;
		} 
		sf("%c",&c);
	}
	N1=i;
	for(i=0,c=0;c!='\n';i++)
	{
		q=(struct link *)malloc(sizeof(struct link));
		sf("%d%d",&(q->a),&(q->n));
		if(first2==NULL)
		{
			first2=p2=q;
		}
		else
		{
			p2->next=q;
			p2=p2->next;
		} 
		sf("%c",&c);		
	}
	N2=i;
	for(i=0,p1=first1;i<N1;i++)
	{
		for(j=0,p2=first2;j<N2;j++,p2=p2->next)
		{
			q=(struct link *)malloc(sizeof(struct link));
			q->a=(p1->a)*(p2->a);
			q->n=(p1->n)+(p2->n);
			q->next=NULL;
			if(first==NULL)
			{
				first=p=q;
			}
			else
			{
				p->next=q;
				p=p->next;
			}
		}
		p1=p1->next;
	}
	N=N1*N2;
	for(i=0,p=first,q=first;i<N;i++)
	{
		for(j=i,q=p->next,p1=p;j<N-1&&q!=NULL;j++)
		{
			if((p->n)==(q->n))
			{
				p->a=(p->a)+(q->a);
				p1->next=p1->next->next;
				p2=q;
				q=q->next;
				free(p2);
				N--;
			}
			else
			{
				q=q->next;
				p1=p1->next;
			}
		}
		p=p->next;
	}
	for(i=0;i<N;i++)
	{
		for(j=0,p=first;j<N-1;j++,p=p->next)
		{
			if((p->n)<(p->next->n))
			{
				temp=p->a;
				p->a=p->next->a;
				p->next->a=temp;
				temp=p->n;
				p->n=p->next->n;
				p->next->n=temp;
			}
		}
	}
	for(i=0,p=first;i<N;i++,p=p->next)
	{
		pf("%d %d ",p->a,p->n);
	}
}

