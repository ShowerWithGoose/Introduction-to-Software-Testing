#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	char c;
	struct node {
    	int x;
    	int z;
    	struct node * next;
	};
	typedef struct node *Nodeptr;
	typedef struct node Node;
	Nodeptr list1,list2,p,q,list,t,s,tmp;
	list1=(Nodeptr)malloc(sizeof(Node));
	list2=(Nodeptr)malloc(sizeof(Node));
	list=(Nodeptr)malloc(sizeof(Node));
	list->next=NULL;
	scanf("%d%d%c",&(list1->x),&(list1->z),&c);
	p=list1;
	while(c!='\n')
	{
		p->next=(Nodeptr)malloc(sizeof(Node));
		p=p->next;
		scanf("%d%d%c",&(p->x),&(p->z),&c);
	}
	p->next=NULL;
	scanf("%d%d%c",&(list2->x),&(list2->z),&c);
	p=list2;
	while(c!='\n')
	{
		p->next=(Nodeptr)malloc(sizeof(Node));
		p=p->next;
		scanf("%d%d%c",&(p->x),&(p->z),&c);
	}
	p->next=NULL;
	p=list1;
	list->x=list1->x*list2->x;
	list->z=list1->z+list2->z;
	while(p!=NULL)
	{
		q=list2;
		while(q!=NULL)
		{
			if(p==list1&&q==list2)
			{
				q=q->next;
				continue;
			}
			t=list;
			while(t!=NULL&&t->z>q->z+p->z)
			{
				s=t;
				t=t->next;
			}
			if(t==list)
			{
				if(t->z==q->z+p->z) t->x+=q->x*p->x;
				else
				{
					tmp=(Nodeptr)malloc(sizeof(Node));
					tmp->x=p->x*q->x;
					tmp->z=p->z+q->z;
					tmp->next=list;
					list=tmp;
				}
			}
			else if(t==NULL)
			{
				t=(Nodeptr)malloc(sizeof(Node));
				t->x=p->x*q->x;
				t->z=p->z+q->z;
				t->next=NULL;
				s->next=t;
			}
			else if(t->z==q->z+p->z) t->x+=q->x*p->x;
			else
			{
				tmp=(Nodeptr)malloc(sizeof(Node));
				tmp->next=t;
				s->next=tmp;
				tmp->x=p->x*q->x;
				tmp->z=p->z+q->z;
			}
			q=q->next;
		}
		p=p->next;
	}
	t=list;
	printf("%d %d ",t->x,t->z);
	while(t->next!=NULL)
	{
		t=t->next;
		printf("%d %d ",t->x,t->z);
	}
	return 0;
}

