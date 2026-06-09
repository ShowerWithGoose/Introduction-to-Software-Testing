#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<math.h>
#include <malloc.h>

int in[100];

typedef struct Node
{
    int data;
    struct Node *next;
}Node;

typedef struct Stack
{
    Node * top;
    Node * bot;
}Stack;

void init_stack(Stack * p)
{
    p->bot = p->top = (Node *) malloc (sizeof(Node));
    p->bot->next = NULL;
}

int empty(Stack *p)
{
    if (p->top == p->bot)
        return 1;
    else
        return 0;
}

void push(Stack *p, int val)
{
    Node * pNew = (Node *) malloc (sizeof(Node));
    pNew->data = val;
    pNew->next = p->top;

    p->top = pNew;
    return;
}

int pop(Stack *p, int *pVal)
{
    Node *pWork = p->top;
    if (empty(p))
        return 0;

    *pVal = p->top->data;
    p->top = p->top->next;
    free(pWork);
    return 1;
}

int main()
{
    int cnt = 0;
    
    while(~scanf("%d",&in[cnt++])){
    	if(in[cnt-1]==-1) break;
	}

    Stack s;
    init_stack(&s);

    int *p = in;

    while(*p != -1)
    {
        if (*p == 1)
        {
			push(&s, *(p+1));

            p+=2;
        }
        else if (*p == 0)
        {
            int popVal = 0;
            if(pop(&s, &popVal))
                printf("%d ",popVal);
            else
                printf("error ");
            p+=1;
        }
}    
        
    return 0;
}

