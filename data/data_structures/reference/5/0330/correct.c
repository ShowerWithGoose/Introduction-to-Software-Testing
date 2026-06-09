#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct num{
	int coe;
	int exp;
	struct num* link;
}node,*links;
links p,q,r,m,n,head1=NULL,head2=NULL,head3=NULL;
int a,b,flag=0;
int word1[10000];
int word2[10000];
int main()
{
	char c;
	int n=0;
	int i=0,j=0,k;
	 	while((c=getchar())!='\n')
	 	{
	 		if(c!=' ')
	 		{
	 			n=n*10+c-'0';
	 		}
	 		if(c==' ')
	 		{
	 			word1[i]=n;
	 			i++;
	 			n=0;
	 		}
	 	}
	 	word1[i]=n;
	 	for(k=0;k<=i;k=k+2)
	 	{
	 		p=(links)malloc(sizeof(node));
	 		p->coe=word1[k];
	 		p->exp=word1[k+1];
	 		p->link=NULL;
	 		if(head1==NULL)
	 		{
	 		head1=p;
	 		}
	 		else
	 		{
	 		r->link=p;
	 		}
	 		r=p;
	 	}
	 	n=0;
	 	while((c=getchar())!='\n')
	 		{
	 			if(c!=' ')
	 			{
	 				n=n*10+c-'0';
	 			}
	 			if(c==' ')
	 			{
	 				word2[j]=n;
	 				j++;
	 				n=0;
	 			}
	 		}
	 		word2[j]=n;
	 		for(k=0;k<=j;k=k+2)
	 		{
	 			p=(links)malloc(sizeof(node));
	 			p->coe=word2[k];
	 			p->exp=word2[k+1];
	 			p->link=NULL;
	 			if(head2==NULL)
	 			{
	 			head2=p;
	 			}
	 			else
	 			{
	 			r->link=p;
	 			}
	 			r=p;
	 		}
	p=head1;
	q=head2;
	while(q!=NULL)//第一个多项式最高项*第二个多项式每一项 
	{
		r=(links)malloc(sizeof(node));
		r->coe=(p->coe)*(q->coe);
		r->exp=(p->exp)+(q->exp);
		r->link=NULL;
		if(head3==NULL)
		{
			head3=r;
		}
		else
		{
			m->link=r;
		}
		m=r;
		q=q->link;
	}
	for(p=head1->link;p!=NULL;p=p->link) 
	{
		for(q=head2;q!=NULL;q=q->link)
		{
			r=(links)malloc(sizeof(node));
			r->coe=(p->coe)*(q->coe);
			r->exp=p->exp+q->exp;
			r->link=NULL;
			m=head3;
			while(m->link!=NULL)
			{	
				if(m->link->exp==r->exp) 
				{
					m->link->coe=m->link->coe+r->coe;
					flag=1;
				}
				else if(r->exp<m->exp&&r->exp>m->link->exp)
				{
					r->link=m->link;
					m->link=r;
					flag=1; 
				}
				m=m->link;
			}
			if(flag==0)
			{
				m->link=r;
			}
			flag=0;
		}
		}
	for(p=head3;p!=NULL;p=p->link)
			{
				if(p->coe!=0) 
				printf("%d %d ",p->coe,p->exp);
			}
	}

