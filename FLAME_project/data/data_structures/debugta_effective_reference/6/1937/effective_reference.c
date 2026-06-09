#include<stdio.h>
#include<stdlib.h>
#define max 100
struct zha{
	int data;
	struct zha* next;
};
typedef struct zha list;

int main(){
	int c;
	int sum=0;
	char t;
	list *head,*p,*q;
	
	head=(list*)malloc(sizeof(list));
	head->next =NULL;
	p=head;
	while(1)
	{
		scanf("%d",&c);
		if(c!=-1)
		{
			t=getchar();
		}
		if(c==1)
		{
			if(sum==100)
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
				sum++;
			}
		}
		else if(c==0)
		{
			if(sum==0)
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
				sum--;
			}
		}
		else if(c==-1)
		{
			break;
		}
	}
	
	return 0;
}

