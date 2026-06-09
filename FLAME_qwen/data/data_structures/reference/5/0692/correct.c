#include<stdio.h>
typedef struct Term{
	int mod,exp;
	struct Term*next;
}term;
int main()
{
	term*head1=NULL,*tail1=NULL;
	char c=' ';
	while(c==' ')
	{
		term*p=(term*)malloc(sizeof(term));
		scanf("%d%d",&p->mod,&p->exp);		
		if(head1==NULL)
		{
			head1=p;tail1=p;
		}
		tail1->next=p;tail1=p;p->next=NULL;
		c=getchar();
	}
	c=' ';
	term*head2=NULL,*tail2=NULL;
	while(c==' ')
	{
		term temp,*cur=head1,*x=head2,*cur2=x;
		scanf("%d%d",&temp.mod,&temp.exp);
		for(;cur!=NULL;cur=cur->next)
		{
			int num=temp.exp+cur->exp;
			for(cur2=x;cur2!=NULL;cur2=cur2->next)
			{
				if(num==cur2->exp)
				{
					cur2->mod+=((temp.mod)*(cur->mod));
					break;
				}
				else if(num>cur2->exp)
				{
					term*p=(term*)malloc(sizeof(term));
					p->exp=num;p->mod=(temp.mod)*(cur->mod);
					x->next=p;p->next=cur2;
					break;
				}
				x=cur2;
			}
			if(cur2==NULL)
			{
				term*p=(term*)malloc(sizeof(term));
				p->exp=num;p->mod=temp.mod*cur->mod;		
				if(head2==NULL)
				{
					head2=p;tail2=p;
				}
				tail2->next=p;tail2=p;p->next=NULL;
			}
		}
		c=getchar();	
	}
	term*cur=head2;
	for(;cur!=NULL;cur=cur->next)
		printf("%d %d ",cur->mod,cur->exp);
	return 0;
}

