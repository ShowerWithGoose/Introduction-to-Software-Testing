#include<stdio.h>
#include<malloc.h>
#include<string.h>

typedef struct node{
	int data;
	struct node * link;
}NODE,*PNODE;

typedef struct stack{
	PNODE pTop;
	PNODE pBottom;
}STACK,*PSTACK;

int capacity;
//º¯ÊýÉùÃ÷ 
void init(PSTACK);
void push(PSTACK);
void pop(PSTACK);
int is_emptyfull(PSTACK);

int main(){
	STACK S;
	init(&S);
	int order;
	do{
		scanf("%d",&order);
		if(order==1)push(&S);
		if(order==0)pop(&S);
	}while(order!=-1);
	return 0;
}

void init(PSTACK ps){
	ps->pTop=(PNODE)malloc(sizeof(NODE));
	ps->pTop->link=NULL;
	ps->pBottom=ps->pTop;
	capacity=0;
}

int is_emptyfull(PSTACK ps){
	if(capacity==100)return 1;
	if(ps->pTop==ps->pBottom)return 2;
	else return 0;
}

void pop(PSTACK ps){
	if(is_emptyfull(ps)==2)printf("error ");
	else{
		PNODE p;
		p=ps->pTop;
		printf("%d ",p->data);
		ps->pTop=p->link;
		free(p);
		capacity--;
	}
}

void push(PSTACK ps){
	if(is_emptyfull(ps)==1)printf("error ");
	else{
		PNODE p;
		p=(PNODE)malloc(sizeof(NODE));
		p->link=ps->pTop;
		ps->pTop=p;
		scanf("%d",&(p->data));
		capacity++;
	}
}

