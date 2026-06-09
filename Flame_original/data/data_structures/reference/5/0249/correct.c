#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

typedef struct node
{
	int co;
	int in;
	struct node *next;
}node,*ptr;

ptr generate_nodes(){
	ptr head,temp,p;
	head=temp=p=NULL;
	char c;
	do
	{
		temp=(ptr)malloc(sizeof(node));
		scanf("%d%d%c",&temp->co,&temp->in,&c);
		if (head==NULL)
		{
			head=p=temp;
			p->next=NULL;
		}else{
			p->next=temp;
			p=temp;
		}
	} while (c!='\n');
	p->next=NULL;
	return head;
}

ptr multi_nodes(ptr head){
	ptr temp,p,pp;
	ptr result_head,p2;
	result_head=p2=NULL;
	int co,in;
	char c;
	do
	{
		p=head;
		scanf("%d%d%c",&co,&in,&c);
		while (p!=NULL)
		{
			temp=(ptr)malloc(sizeof(node));
			temp->co=co*p->co;
			temp->in=in+p->in;
			if (result_head==NULL)
			{
				result_head=p2=temp;
				p2->next=NULL;
			}else{
				for ( p2 = result_head; p2!=NULL; pp=p2,p2=p2->next)
				{
					if (temp->in > p2->in)
					{
						if (p2==result_head)
						{
							temp->next=p2;
							result_head=temp;
						}else{
							pp->next=temp;
							temp->next=p2;
						}
						break;
					}else if (temp->in == p2->in)
					{
						p2->co+=temp->co;
						break;
					}
				}
				if (p2==NULL)
				{
					pp->next=temp;
					temp->next=NULL;
				}
			}
			p=p->next;
		}
	} while (c!='\n');
	return result_head;
}

void output(ptr result_head){
	while (result_head!=NULL)
	{
		printf("%d %d ",result_head->co,result_head->in);
		result_head=result_head->next;
	}
	
}

int main(){
	ptr head,result_head;
	head=generate_nodes();
	result_head=multi_nodes(head);
	output(result_head);
	return 0;
}
