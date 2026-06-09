#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
struct number
{
	int before;
	int x;
	struct number *next;
};
typedef struct number *listp;
typedef struct number list;
listp p=NULL,q=NULL,t=NULL,head1=NULL,head2=NULL,p1=NULL,p2=NULL,head=NULL;
int main ()
{
	int i,j,k,n1=0,n2=0,m=0,n=0,before_,x_;
	char a[500],b[500];
	gets(a);
	gets(b);
	for (i=0;a[i]!='\0';i++)//输入第一个多项式 
	{
		q=(listp)malloc(sizeof(list));
		q->next=NULL;
		
		for(;a[i]!=' ';i++)
		{
			m=10*m+a[i]-'0';
		}
		q->before=m;
		m=0;
		i++;
		for(;a[i]!=' '&&a[i]!='\0';i++)
		{
			n=10*n+a[i]-'0';
		}
	
		q->x=n;
		n=0;
		if(head1==NULL)
			head1=q;
		else
		{
		
			p->next=q;
		}
		p=q;
		if(a[i]=='\0')
		{
			break;
		}
	}
	
	for (p=head1;p!=NULL;p=p->next)
	{
		n1++;
		/*printf("%d %d\n",p->before,p->x);*/
	}
	for (i=0;b[i]!='\0';i++)//输入第二个多项式 
	{
		q=(listp)malloc(sizeof(list));
		q->next=NULL;
	
		for(;b[i]!=' ';i++)
		{
			m=10*m+b[i]-'0';
		}
		q->before=m;
		m=0;
		i++;
		for(;b[i]!=' '&&b[i]!='\0';i++)
		{
			n=10*n+b[i]-'0';
		}
		q->x=n;
		n=0;
		if(head2==NULL)
			head2=q;
		else
		{
		
			p->next=q;
		}
		p=q;
		if(b[i]=='\0')
		{
			break;
		}
		
	}
	for (p=head2;p!=NULL;p=p->next)
	{
		n2++;
	/*	printf("%d %d\n",p->before,p->x);*/
	} 
	
	p1=head1;
	p2=head2;
	for (i=0;i<n1;i++)//将相乘后的系数和指数存入新链表 
	{
		for(j=0;j<n2;j++)
		{
			p=(listp)malloc(sizeof(list));
		
			p->before=p1->before*p2->before;
			p->x=p1->x+p2->x;
			if (head==NULL)
			{
				head=p;
			}
			else
			{
				q->next=p;
			}
			q=p;
			p->next=NULL;
			p2=p2->next;
		}
		p1=p1->next;
		p2=head2;
	}
	p=head;
	q=p->next;
	n=n1*n2;
	m=n;
		/*for(i=0;i<n;i++)
	{
		printf("%d %d  ",p->before,p->x);
		p=p->next;
	}
	p=head;
	q=p->next;*/
	for(i=0;i<n-1;i++)//排序 
	{
		p=head;
		q=p->next;
		for(j=0;j<n-1-i;j++)
		{
			
			if(p->x<q->x)
			{
				before_=p->before;
				x_=p->x;
				p->before=q->before;
				p->x=q->x;
				q->before=before_;
				q->x=x_;
			}
		/*	if(p->x==q->x)
			{
				p->before+=q->before;
				p->next=q->next;
				free(q);
				q=p->next;
				m--;
				
			}*/ 
			p=p->next;
			q=p->next;
		}
	}
	p=head;
/*	for(i=0;i<n;i++)
	{
		printf("%d %d  ",p->before,p->x);
		p=p->next;
	}
	printf("\n\n\n");*/
	for (p=head,q=p->next;q!=NULL;p=p->next,q=p->next)
	{
		while(p->x==q->x)
		{
			p->before+=q->before;
			p->next=q->next;
			free(q);
			q=p->next;
		}
	}
	p=head;
	for (;p!=NULL;p=p->next)
	{
		printf("%d %d ",p->before,p->x);
	
	}
	free(p); 
	return 0;
}

