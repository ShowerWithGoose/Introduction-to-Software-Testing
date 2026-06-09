#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
struct node{
	int xishu;
	int mi;
	struct node *next;
};
int main()
{
	int a,n,i,j;
	char c;
	struct node *head1,*head2=NULL,*p1,*p2,*q1,*q2,*m=NULL;
	head1=p1=NULL;
	do{
		scanf("%d%d%c",&a,&n,&c);
		q1=(struct node *)malloc(sizeof(struct node));
		q1->xishu=a;q1->mi=n;q1->next=NULL;
		if(head1==NULL) head1=p1=q1;
		else {
			p1->next=q1;
			p1=p1->next;
		}
	}while(c!='\n');
	do{
		scanf("%d%d%c",&a,&n,&c);
		for(p1=head1;p1!=NULL;p1=p1->next)
		{
			i=a*p1->xishu;
			j=n+p1->mi;
			q2=(struct node *)malloc(sizeof(struct node));
			q2->xishu=i;
			q2->mi=j;
			q2->next=NULL;
			if(head2==NULL)
			head2=p2=q2;
			else {
				for(p2=head2;p2!=NULL;m=p2,p2=p2->next)
				{//排序 
					if(q2->mi>p2->mi)
					{
						if(p2==head2)
						{
							q2->next=head2;head2=p2;
							break;
						}
						else{//q插到p的前面 
							q2->next=p2;
							m->next=q2;
							break;
						}
					}
					else if(p2->mi==q2->mi)
					{
						p2->xishu+=q2->xishu;
						break;
					}
				}
				if(p2==NULL) m->next=q2;
			}
		}
	}while(c!='\n');
	for(p2=head2;p2!=NULL;p2=p2->next)
	printf("%d %d ",p2->xishu,p2->mi);
	printf("\n"); 
	return 0; 
}

