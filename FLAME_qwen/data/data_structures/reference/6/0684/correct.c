#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node* next; 
};
struct stack
{
	struct node* top;
	int size;
};
struct node* create(int b)
{
	struct node* f;
	f=(struct node*)malloc(sizeof(struct node));
	f->data=b;f->next=NULL;
	return f;
};
int main()
{
	struct stack* zhan;
	struct node* q;
	zhan=NULL;q=NULL;
	
	int a,b;
	while((scanf("%d",&a))!=-1)
	{
		if(a==1)
		{
		    scanf("%d",&b);
			if(zhan==NULL)
			{
				zhan=(struct stack*)malloc(sizeof(struct stack));zhan->size=0;
       			q=create(b);
			    zhan->top=q;(zhan->size)++;
			}
			else
			{
				q=create(b);
				q->next=zhan->top;
				zhan->top=q;(zhan->size)++;
			}
		}
		else if(a==0)
		{
			if(zhan->size==0){printf("error ");continue;}
			printf("%d ",zhan->top->data);
			zhan->top=zhan->top->next;zhan->size--;
		}
	}
	return 0;
} 



