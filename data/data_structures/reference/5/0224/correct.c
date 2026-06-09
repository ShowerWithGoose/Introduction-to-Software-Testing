#include<stdio.h>
#include<stdlib.h>
struct Node{
	int coe;
	int pow;
	struct Node *next;
};
int main()
{
	int a,n,a2,n2;
	char c;
	struct Node *head1,*head2=NULL,*p1,*p2,*q1,*q2,*p0=NULL;
	head1=p1=NULL;
	do{
		scanf("%d%d%c",&a,&n,&c);
		q1=(struct Node*)malloc(sizeof(struct Node));
		q1->coe=a;q1->pow=n;q1->next=NULL;
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
			a2=a*p1->coe;
			n2=n+p1->pow;
			q2=(struct Node*)malloc(sizeof(struct Node));
		    q2->coe=a2;
		    q2->pow=n2;
		    q2->next=NULL;
		    if(head2==NULL)
		    {
		    	head2=p2=q2;
			}
			else
			{
				for(p2=head2;p2!=NULL;p0=p2,p2=p2->next)
				{
					if(q2->pow>p2->pow)
					{
						if(p2==head2)
						{
							q2->next=head2;head2=q2;break;
						}
						else
						{
							q2->next=p2;p0->next=q2;break;
						}
					}
					else if(q2->pow==p2->pow)
					{
						p2->coe+=q2->coe;
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
		printf("%d %d ",p2->coe,p2->pow);
	}
	printf("\n");
	return 0;
}

