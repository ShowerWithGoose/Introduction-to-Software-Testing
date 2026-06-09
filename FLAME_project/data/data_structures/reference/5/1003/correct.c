#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
struct link{
	int a;
	int b;
	struct link *next;
	struct link *pre;
};
struct link *first1=NULL,*tail1,*q,*p,*first2=NULL,*tail2,*r,*first3=NULL,*tail3,*temp;

int main()
{
	int i,j;
	char pu={0};
	int s1=0;
	int s2=0;
	while(scanf("%d",&i)!=EOF)
	{
		s1++;
		scanf("%d",&j);
		pu=getchar();

		
				
		q=(struct link*)malloc(sizeof(struct link));
		q->a=i;
		q->b=j;
		q->next=NULL;
		if(first1==NULL)
			first1=tail1=q;
		else
		{
			q->pre=tail1;
			tail1->next=q;
			tail1=tail1->next;
		}
		if(pu=='\n')
		{
			break;
		}
		
	}
	q=first1;
	pu=0;
	while(scanf("%d",&i)!=EOF)
	{
		s2++;
		scanf("%d",&j);
		pu=getchar();	
	
		p=(struct link*)malloc(sizeof(struct link));
		p->a=i;
		p->b=j;
		p->next=NULL;
		if(first2==NULL)
			first2=tail2=p;
		else
		{
			tail2->next=p;
			tail2=tail2->next;
		}
		if(pu=='\n')
		{
			break;
		}
		
	}
	p=first2;
	for(i=0;i<s1;i++)
	{
		if(i!=0)
		{
			q=q->next;
			p=first2;
		}
		
		for(j=0;j<s2;j++)
		{
  			r=(struct link*)malloc(sizeof(struct link));
			r->a=(q->a)*(p->a);
			r->b=(q->b)+(p->b);
			
			p=p->next;
			r->next=NULL;
			int flag=0; 
			if(j!=0||i!=0)
			{
				temp=first3;	
				while(temp!=NULL)
				{
					if((temp->b)==(r->b))
					{
						(temp->a)=(temp->a)+(r->a);
						flag=1;
						break;
						
					}
					else if((r->b)>(temp->b)) 
					{
						r->pre=temp->pre;
						temp->pre->next=r;
						temp->pre=r;
						r->next=temp;
						flag=1;
						break;
					}
					temp=temp->next;
				}				
			}
			if(flag==0)
			{
				if(first3==NULL)
					first3=tail3=r;
				else
				{
					r->pre=tail3;
					tail3->next=r;
					tail3=tail3->next;
				}			
			}
		}
		
	}
	temp=first3;
	while(temp!=NULL)
	{
		printf("%d %d ",temp->a,temp->b);
		temp=temp->next;
	}
	return 0;
}

