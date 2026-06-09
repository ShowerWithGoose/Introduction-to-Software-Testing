#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct node
{
	struct node *front,*next;
	int num;
}node;
node *tail=NULL;int capacity=0,in;
int push(int num)
{
	if(capacity>100){printf("error ");return -1;}
	node *p=(node *)malloc(sizeof(node));
	p->front=tail,p->num=num,p->next=NULL;
	tail->next=p;
	tail=p;
	capacity++;
	return 1;//成功
}
int pop()
{
	if(capacity==0){printf("error ");return -1;}
	int tmp=tail->num;
	node *q=tail->front;
	q->next=NULL;
	free(tail);tail=q;
	capacity--;
	printf("%d ",tmp);
	return 1;//成功
}
int main()
{
	node *stack=(node *)malloc(sizeof(node));//stack头节点
	stack->front=NULL,stack->next=NULL;
	tail=stack;
	while(1)
	{
		scanf("%d",&in);
		if(in==-1)break;
		if(in==0)pop();
		if(in==1)scanf("%d",&in),push(in);
	}
	return 0;
}
