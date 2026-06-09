#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
struct Node
{
	int coe;
	int pow;
	struct Node *next;
};
int main()
{
	int a,n;
	char c;
	struct Node *head,*p,*p1,*p2,*q,*q1,*q2,*p0,*head1,*head2;
	head=p=NULL;
	head1=p1=NULL;
	head2=p2=NULL;
	do{
		scanf("%d%d%c",&a,&n,&c);
		q=(struct Node*)malloc(sizeof(struct Node));
		q->coe=a;
		q->pow=n;
		q->next=NULL;
		if(head==NULL)
		head=p=q;
		else
		{
			p->next=q;
			p=p->next;
		}
	}while(c!='\n');
	scanf("%d%d%c",&a,&n,&c);
	for(p=head;p!=NULL;p=p->next)
	{
		q1=(struct Node*)malloc(sizeof(struct Node));
		q1->coe=a*(p->coe);
		q1->pow=n+(p->pow);
		q1->next=NULL;
		if(head1==NULL)
		head1=p1=q1;
		else
		{
			p1->next=q1;
			p1=p1->next;
		}
	}
	if(c!='\n')
	{
		do
		{
			scanf("%d%d%c",&a,&n,&c);
			for(p=head;p!=NULL;p=p->next)
			{	
				q2=(struct Node*)malloc(sizeof(struct Node));
				q2->coe=a*(p->coe);
				q2->pow=n+p->pow;
				q2->next=NULL;
				for(p1=head1;p1!=NULL;p0=p1,p1=p1->next)
				{
					if(q2->pow>p1->pow)
					{
						if(p1==head1)
						{
							q2->next=head1;
							head1=q2;
							break;
						}
						else
						{
							q2->next=p1;
							p0->next=q2;
							break;
						}
					}
					else if(q2->pow==p1->pow)
					{
						p1->coe+=q2->coe;
						break;
					}
				}
				if(p1==NULL)
				p0->next=q2;
			}
	    }while(c!='\n');
	}
	
	for(p1=head1;p1!=NULL;p1=p1->next)
	printf("%d %d ",p1->coe,p1->pow);
	return 0;
}


