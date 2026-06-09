#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
	int data;
	struct Node *pNext;
}NODE,*PNODE;
typedef struct Stack
{
	PNODE pTop;
	PNODE pBottom;
}STACK,*PSTACK;
void init(PSTACK pS);
void push(PSTACK pS,int val);
void traverse(PSTACK pS);
int empty(PSTACK pS);
int pop(PSTACK pS,int *val);
int main()
{
	STACK S;
	init(&S);
	int op,val,cnt=0;
	while(scanf("%d",&op))
	{
		if(op==1)
		{
			scanf("%d",&val);
			if(cnt<100)
			{
				push(&S,val);
				cnt++; 
			}
			else
			{
				printf("error ");
			}	
		}
		else if(op==0)
		{
			if(pop(&S,&val))
			{
				printf("%d ",val);
			}
			else
			printf("error ");
		}
		else
		return 0;
	}
	return 0;
}
void init(PSTACK pS)
{
    pS->pTop=(PNODE)malloc(sizeof(NODE));
	if(pS->pTop == NULL)
	{
		printf("·ÖÅäÊ§°Ü");
		exit(-1); 
	}
	pS->pBottom=pS->pTop;
	pS->pTop->pNext = NULL; 	
} 
void push(PSTACK pS,int val)
{
	PNODE pNew=(PNODE)malloc(sizeof(NODE));
	if(pNew == NULL)
	{
		printf("·ÖÅäÊ§°Ü");
		exit(-1); 
	}
	pNew->data = val;
	pNew->pNext = pS->pTop;
	pS->pTop = pNew;
	return;
}
void traverse(PSTACK pS)
{
	PNODE p=pS->pTop ;
	while(p!=pS->pBottom)
	{
		printf("%d ",p->data );
		p=p->pNext ;
	}
	printf("\n");
	return;
}
int empty(PSTACK pS)
{
	if(pS->pBottom == pS->pTop )
	return 1;
	return 0;
}
int pop(PSTACK pS,int *val)
{
	if(empty(pS))
	return 0;
	else
	{
		PNODE r=pS->pTop ;
		*val=r->data ;
		pS->pTop = pS->pTop->pNext;
		free(r);
		r=NULL;
		return 1;
	}
}


