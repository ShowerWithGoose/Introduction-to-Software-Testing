#include<stdio.h>
#include<math.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
#include<ctype.h>

struct multi
{
	int coeffi;
	int index;
	struct multi *next;
};

typedef struct multi *Multiptr;
typedef struct multi Multi;

#define MAXLINE 1024
int main()
{
	int a,n,a1,n1;
	char c;
	Multiptr head1,head2=NULL,p1,p2,q1,q2,p0=NULL;
	head1=p1=NULL;
	do
	{
		scanf("%d%d%c",&a,&n,&c);
		q1=(Multiptr)malloc(sizeof(Multi));
		q1->coeffi=a;
		q1->index=n;
		q1->next=NULL;
		if(head1==NULL)
		{
			head1=p1=q1;
		}
		else
		{
			p1->next=q1;
			p1=p1->next;
		}
	}while(c!='\n');
	do{
		scanf("%d%d%c",&a,&n,&c);
		for(p1=head1;p1!=NULL;p1=p1->next)
		{
			//第二个多项式每项与第一个相乘 
			a1=a*p1->coeffi;
			n1=n+p1->index;
			q2=(Multiptr)malloc(sizeof(Multi));
			q2->coeffi=a1;
			q2->index=n1;
			q2->next=NULL;
			if(head2==NULL)
			{
				head2=p2=q2;
			}
			else
			{
				for(p2=head2;p2!=NULL;p0=p2,p2=p2->next)
				{
					if(q2->index>p2->index)
					{
						if(p2==head2)
						{
							q2->next=head2;
							head2=q2;
							break;
						}
						else
						{
							q2->next=p2;
							p0->next=q2;
							break;
						}
					}
					else if(q2->index==p2->index)
					{
						p2->coeffi+=q2->coeffi;
						break;
					}
				}
				if(p2==NULL)
				{
					p0->next=q2;
				}
			}
		}
	}while(c!='\n');
	for(p2=head2;p2!=NULL;p2=p2->next)
	{
		printf("%d %d ",p2->coeffi,p2->index);
	}
	return 0;
}

