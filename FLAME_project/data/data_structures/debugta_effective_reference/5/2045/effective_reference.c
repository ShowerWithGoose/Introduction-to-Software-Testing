#include<stdio.h>
#include<stdlib.h>
struct Node{
	int coe;
	int exp;
	struct Node *next;
};
typedef struct Node *list;
void insert (list head,list p)
{
	list L=head;
	while(L!=NULL)
	{
		if(L->exp==p->exp)
		{
		L->coe=L->coe+p->coe;
		break;
		}
		else if(L->next==NULL&&L->exp>p->exp)
		{
		L->next=p;
		break;
	}
		else if(L->exp>p->exp&&L->next->exp<p->exp)
		{
			p->next=L->next;
			L->next=p;
			break;
		}
		//else if(L->exp<p->exp&&L!=NULL)
		//{
//			p->next=L;
//			break;
//		}
		//else if(L->exp>p->exp&&L->next==NULL)
		//{
		//	L->next=p;
		//	break;
		 //}
		 else 
		 L=L->next;
	}
}
int main()
{
	int a,n;
	char c;
	list p1=NULL,p=NULL,head1=NULL;
	while(1)
	{
		scanf("%d%d%c",&a,&n,&c);
		p1=(list)malloc(sizeof(struct Node));
		p1->coe=a;
		p1->exp=n;
		p1->next=NULL;
		if(head1==NULL)
		{
			head1=p1;
			p=p1;
		}
		else
		{
			p->next=p1;
			p=p1;
		}
		if(c=='\n')
		break;
	}
	p1=head1;
	list p2=NULL,q2=NULL,head2=NULL;
	do	{
		scanf("%d%d%c",&a,&n,&c);
		p2=(list)malloc(sizeof(struct Node));
		p2->coe=a;
		p2->exp=n;
		p2->next=NULL;
		if(head2==NULL)
		{
			head2=p2;
			q2=p2;
		}
		else
		{
			q2->next=p2;
			q2=p2;
		}
	}while(c!='\n');
	p2=head2;
//	for(p2=head2;p2!=NULL;p2=p2->next)
//	printf("%d %d\n",p2->coe,p2->exp);
	list p3=NULL,head3=NULL;
	while(p1!=NULL)
	{
		for(p2=head2;p2!=NULL;p2=p2->next)
		{
			p3=(list)malloc(sizeof(struct Node));
			p3->coe=p1->coe*p2->coe;
			p3->exp=p1->exp+p2->exp;
			p3->next=NULL;
			if(head3==NULL)
			head3=p3;
			else
			insert(head3,p3);
			//p2=p2->next;
		}
		p1=p1->next;
	}
	for(p3=head3;p3!=NULL;p3=p3->next)
	printf("%d %d ",p3->coe,p3->exp);
	return 0;
}
	
	



