#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct node{
	int data;
	int idex;
	struct node* next;
}NODE,*PNODE;

PNODE creat_list() 
{
	PNODE head=(PNODE)malloc(sizeof(NODE));
	PNODE tail=head;
	tail->next=NULL;
	int val1,val2;
	char c;
	//scanf("%d%d%c",&val1,&val2,&c);
	do{
		scanf("%d%d%c",&val1,&val2,&c);
				PNODE new=(PNODE)malloc(sizeof(NODE));
				new->data=val1;
				new->idex=val2;
				tail->next=new;
				new->next=NULL;
				tail=new;
	}while(c!='\n');
	return head;
}

void traverse_list(PNODE pHead)
{
	PNODE r=pHead->next;
    while(r!=NULL)
    {
		printf("%d %d ",r->data,r->idex);
		r=r->next;
	}
	return ;
}

int len_list(PNODE pHead)
{
	PNODE r=pHead->next;
	int len=0;
	while(r!=NULL)
	{
		len++;
		r=r->next;
	}
	return len;
}

void sort_list(PNODE pHead)
{
	int i,j,len,t1,t2;
	PNODE p,q;
	len=len_list(pHead);
	for(i=0,p=pHead->next;i<len;i++,p=p->next)
	{
		for(j=i+1,q=p->next;j<len;j++,q=q->next)
		{
			if(p->idex<q->idex)
			{
				t1=p->data;
				p->data=q->data;
				q->data=t1;
				t2=p->idex;
				p->idex=q->idex;
				q->idex=t2;
			}
		}
	}
}

PNODE search_list(PNODE pHead,int e)
{
	PNODE r=pHead->next;
	int flag=0;
	while(r!=NULL)
	{
		if(r->idex==e)
		{ 
			flag=1;
			break;
		}
		else
		  r=r->next;
	}
	if(flag==1)
	  return r;
	else
	  return NULL ;
}
int main()
{
	PNODE head1,head2,head3,r1,r2;
	head3=(PNODE)malloc(sizeof(NODE));
	PNODE tail=head3;
	tail->next=NULL;
	head1=creat_list();
	head2=creat_list();
    r1=head1->next;
    
    while(r1!=NULL)
    {
    	r2=head2->next;
		while(r2!=NULL)
		{
			PNODE new,p;
			new=(PNODE)malloc(sizeof(NODE));
			new->data=r1->data*r2->data;
			new->idex=r1->idex+r2->idex;
			p=(PNODE)malloc(sizeof(NODE));
			if(search_list(head3,new->idex)!=NULL)//·µ»ØÎ»ÖÃ 
			{
				p=search_list(head3,new->idex);
		    	p->data=p->data+new->data; 	
			}
			else
			{
			    tail->next=new;
				new->next=NULL;
				tail=new;
			}	
			r2=r2->next;
		}
		r1=r1->next;
	}
	sort_list(head3);
	traverse_list(head3);
	//traverse_list(head1);
	//traverse_list(head2);
	return 0;
}



