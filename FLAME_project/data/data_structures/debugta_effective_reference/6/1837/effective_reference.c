#include <stdio.h>
#include <stdlib.h>
typedef struct node node;
struct node
{
	int num;
	node *next;
};

typedef node *nptr;
struct stack
{
	node *list;//代表头指针
	int size; //代表栈的长度 
};
typedef struct stack stack;

nptr getnode()
{
	return (nptr)malloc(sizeof(node));//申请动态内存的函数 
}
void push(stack *shuo,int n)//入栈操作
{
	shuo->size++;
	nptr p=getnode();
	p->next=shuo->list;
	p->num=n;
	shuo->list=p;
} 
void pop(stack *shuo)//出栈操作
{
	if(shuo->size==0) printf("error ");
	else
	{
		nptr p=shuo->list;
		printf("%d ",shuo->list->num);
		shuo->list=shuo->list->next;
		free(p);
		shuo->size--;
	} 
} 
int main()
{
	stack *st=(stack*)malloc(sizeof(stack));//栈的指针
	st->size=0;
	st->list=NULL;
	int n,m;
	while(scanf("%d",&n))
	{
		if(n==-1) return 0;
		else if(n==0)
		{
			pop(st);
		}
		else if(n==1)
		{
			scanf("%d",&m);
			push(st,m);
		}
	}
}

