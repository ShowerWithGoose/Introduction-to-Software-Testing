#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
typedef struct Node
{
int data;
struct Node *next;
}Node;
typedef struct Stack
{
    Node * top;
    Node * pButtom;
}Stack;
void init_stack(Stack * ps);
int is_empty(Stack *ps);
void push_stack(Stack *ps,int val);
int pop_stack(Stack *ps,int*pVal);
int main(int argc,char*argv[])
{
int count =0;
int flag =0;
int inputOperation[100]={0};

int*p = inputOperation;

do
{
scanf("%d",&flag);
        inputOperation[count++]= flag;
}while(flag !=-1);

    Stack s;

init_stack(&s);
    p = inputOperation;
while(*p !=-1)
{
if(*p ==1)
{
if(*(p+1)==1||*(p+1)==0||*(p+1)==-1)//
{
printf("操作序列输⼊错误！\n");
break;
}
push_stack(&s,*(p+1));
p+=2;
}
else if(*p ==0)
{
int popVal =0;
if(pop_stack(&s,&popVal))
printf("%d ",popVal);
else
printf("error ");
p+=1;
}
}
printf("\n");
system("pause");
return 0;
}
void init_stack(Stack * ps)
{
    ps->pButtom = ps->top =(Node *) malloc (sizeof(Node));
    ps->pButtom->next =NULL;
}
int is_empty(Stack *ps)
{
if(ps->top == ps->pButtom)
return 1;
else
return 0;
}
void push_stack(Stack *ps,int val)
{
    Node * pNew =(Node *) malloc (sizeof(Node));
    pNew->data = val;
    pNew->next = ps->top;
    ps->top = pNew;
return;
return;
}
int pop_stack(Stack *ps,int*pVal)
{
    Node *pWork = ps->top;
if(is_empty(ps))
return 0;
*pVal = ps->top->data;
    ps->top = ps->top->next;
free(pWork);
return 1;
}

