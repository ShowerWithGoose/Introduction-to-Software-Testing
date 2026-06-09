#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>
#include<malloc.h>
#define ll long long
#define Maxsize 1000
typedef struct node
{
	int an;
	int e;
	struct node *next;
	int flag;
}lin;
lin*list1,*list2,*anslist,*ptr,*qtr;
lin ss;
lin*temp;
lin* find(lin *aim)
{
	temp=anslist;
	while(temp->next!=NULL)
	{
		if(temp->e==aim->e)
		{
			return temp;
		}
		else temp=temp->next;
	}
	return NULL;
}
int main()
{
	int i,j,maxan,maxe=-1;
	char c;
	lin*p,*q;
	int flag=1;
	while(1)
	{
		q=(lin*)malloc(sizeof(ss));
		scanf("%d %d",&q->an,&q->e);
		if(flag==1)
		{
			list1=q;
			p=q;
			p->next=NULL;
			flag=0;
		}
		else
		{
			p->next=q;
			p=q;
			p->next=NULL;
		}
		scanf("%c",&c);
		if(c=='\n')
		{
			p->next=NULL;
			break;
		}
	}
	flag=1;
	while(1)
	{
		q=(lin*)malloc(sizeof(ss));
		scanf("%d %d",&q->an,&q->e);
		if(flag==1)
		{
			list2=q;
			p=q;
			p->next=NULL;
			flag=0;
		}
		else
		{
			p->next=q;
			p=q;
			p->next=NULL;
		}
		scanf("%c",&c);
		if(c=='\n')
		{
			p->next=NULL;
			break;
		}
	}
	p=list1;
	q=list2;
	flag=1;
	while(q!=NULL)
	{
		while(p!=NULL)
		{
			if(flag==1)
			{
				ptr=(lin*)malloc(sizeof(ss));
				ptr->an=p->an*q->an;
				if(ptr->an==0)continue;
				ptr->e=p->e+q->e;
				p=p->next;
				anslist=ptr;
				qtr=ptr;
				qtr->next=NULL;
				flag=0;
				ptr->flag=0;
			}
			else
			{
				ptr=(lin*)malloc(sizeof(ss));
				ptr->an=p->an*q->an;
				if(ptr->an==0)continue;
				ptr->e=p->e+q->e;
				p=p->next;
				temp=find(ptr);
				if(temp!=NULL)
				{
					temp->an+=ptr->an;
					free(ptr);
				}
				else
				{
					qtr->next=ptr;
					qtr=ptr;
					qtr->next=NULL;
					ptr->flag=0;
				}	
			}
		}
		q=q->next;
		p=list1;
	}
	qtr->next=anslist;
	ptr=anslist;
	qtr=ptr;
	while(anslist!=NULL)
	{
		ptr=anslist;
		do
		{
			if(ptr->flag==1)
			{
				ptr=ptr->next;
				continue;
			}
			if(ptr->e>maxe)
			{
				maxe=ptr->e;
				maxan=ptr->an;
				qtr=ptr;
			}
			ptr=ptr->next;
		}while(ptr!=anslist);
		if(maxe==-1)break;
		printf("%d %d ",maxan,maxe);
		qtr->flag=1;
		maxe=-1;
	}
	return 0;
}


