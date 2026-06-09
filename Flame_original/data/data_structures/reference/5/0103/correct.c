#include<stdio.h>
#include<stdlib.h>
typedef struct Node *nodeptr;
struct Node{
	int Coef;
	int Expon;
	nodeptr next;
};
nodeptr read(void);
nodeptr multi(nodeptr p1,nodeptr p2); 
int main()
{	
	nodeptr p1,p2,ans,ptrl;
	p1=read();
	p2=read();
	ptrl=p1;
	ans=multi(p1,p2);
	ptrl=ans;
	while(ptrl)
	{
		printf("%d %d ",ptrl->Coef,ptrl->Expon);
		ptrl=ptrl->next;
	}
	free(ans);
	free(p1);
	free(p2);	 
	return 0;
}
nodeptr read(void)
{
	nodeptr head=NULL,p,r;
	int temp=' ',coef,expon;
	while(temp!='\n')
	{
		scanf("%d %d",&coef,&expon);
		temp=getchar();
		r=(nodeptr)malloc(sizeof(struct Node));
		r->Coef=coef;
		r->Expon=expon;
		r->next=NULL;
		if(head==NULL)
			head=p=r;
		else
		{
			p->next=r;
			p=p->next;
		}
	}
	return head;
}
nodeptr multi(nodeptr p1,nodeptr p2)
{
	nodeptr head=NULL,p=p1,q,r,i,front;	
	while(p)
	{
		q=p2;
		while(q)
		{
			r=(nodeptr)malloc(sizeof(struct Node));
			r->Coef=p->Coef*q->Coef;
			r->Expon=p->Expon+q->Expon;
			r->next=NULL;
			if(head==NULL)
				head=r;	
			else
			{
				i=head;
				while(i)
				{
					if(i->Expon>r->Expon)
					{
						front=i;
						i=i->next;
					}		
					else if(i->Expon==r->Expon)	
					{
						i->Coef+=r->Coef;
						free(r);
						break;
					}	
					else
					{
						r->next=front->next;
						front->next=r;
						break;
					}
				}
				if(i==NULL)
					front->next=r;
			}
			q=q->next;
		}
		p=p->next;
	}
	i=head;
	while(i)
	{
		if(i->Coef==0)
		{
			p=i;
			front->next=i->next;
			free(p);
		}
		else
		{
			front=i;
			i=i->next;
		}
	}
	return head;
}

