#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
typedef struct bond{
    int a;
    struct bond *next;
}SB;
SB *top; 
void intbond()
{
top=NULL;
}//初始化栈 
int empty()
{
    return top==NULL;
}//检验是否栈空 
void push(int x)
{
    SB *p;
    if((p=(SB*)malloc(sizeof(SB)))==NULL)
    printf("No memory!");
    else{
        p->a=x;
        p->next=top;
        top=p;
    }
}//入栈 
int pop()
{
    SB *p;
    int x;
    if(empty())
    printf("error "); // @@ The function is declared to return int, but when the stack is empty, it prints "error " and does not return a value, causing undefined behavior.
    else
    {
        p=top;
        x=top->a;
        top=top->next;
        free(p);
        return x;
    }
}//出栈 
int main()
{
intbond();
int m,n;
while(~scanf("%d",&m))
{
    if(m==-1)
    break;
    else if(m==0)
    {
        printf("%d ",pop()); // @@ When pop() prints "error " due to empty stack, it does not return a value, so this printf will print an undefined integer.
    }
    else
    {
        scanf("%d",&n);
        push(n);
    }
}
 return 0;
}