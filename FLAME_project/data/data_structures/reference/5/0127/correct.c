#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node{
	int a;
	int x;
	struct node *link;
};
typedef struct node *nodeptr;
typedef struct node Node;
int main()
{
	nodeptr list1,p1,q1;
	list1=NULL;
	char flag;
	while(1>0)
	{
		int s,m;
		q1=(nodeptr)malloc(sizeof(Node));
		scanf("%d %d%c",&s,&m,&flag);
		q1->a=s;
		q1->x=m;
		q1->link=NULL;
		if(list1==NULL)
		{
			list1=p1=q1;
		}
		else
		{
			p1->link=q1;
			p1=p1->link;
		}
		if(flag=='\n')
		{
			break;
		}
	}
	nodeptr list2,p2,q2;
	list2=NULL;
	while(1>0)
	{
		int s,m;
		char flag;
		nodeptr add;
		scanf("%d %d%c",&s,&m,&flag);
		for(p1=list1;p1!=NULL;p1=p1->link)
		{
			q2=(nodeptr)malloc(sizeof(Node));
			q2->a=s*p1->a;
			q2->x=m+p1->x;
			q2->link=NULL;
			if(list2==NULL)
			{
				list2=p2=q2;
			}
			else
			{
				for(p2=list2;p2!=NULL;add=p2,p2=p2->link)
				{
					if(q2->x>p2->x)
					{
						if(p2==list2)
						{
							q2->link=list2;
							list2=q2;
							break;
						}
						else
						{
							q2->link=p2;
							add->link=q2;
							break;
						}
					}
					else if(q2->x==p2->x)
					{
						p2->a+=q2->a;
						break;
					}
				}
				if(p2==NULL)
				{
					add->link=q2;
				}
			}
		}
		if(flag=='\n')
		{
			break;
		}
	}
	for(p2=list2;p2!=NULL;p2=p2->link)
	{
		printf("%d %d ",p2->a,p2->x);
	}
	return 0;
}

