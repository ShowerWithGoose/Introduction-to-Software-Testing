#include<stdio.h>
#include<stdlib.h>
#define max 100
struct zha{
	int data;
	struct zha* next;
};
typedef struct zha list;

int main(){
	int op;
	int vau=0;
	char zhi;
	list *head,*p,*q;
	
	head=(list*)malloc(sizeof(list));
	head->next =NULL;
	p=head;
	while(1)
	{
		scanf("%d",&op);
		if(op!=-1)
		{
			zhi=getchar();
		}
		if(op==1)
		{
			if(vau==100)
			{
				printf("error ");
				continue;
			}
			else
			{
				q=(list*)malloc(sizeof(list));
				q->next =NULL;
				scanf("%d ",&q->data );
				p->next =q;
				p=q;
				vau++;
			}
		}
		else if(op==0)
		{
			if(vau==0)
			{
				printf("error ");
				continue;
			}
			else
			{
				for(p=head,q=head->next ;q->next !=NULL;p=q,q=q->next );
				printf("%d ",q->data );
				p->next =NULL;
				free(q);
				vau--;
			}
		}
		else if(op==-1)
		{
			break;
		}
	}
	
	return 0;
}

