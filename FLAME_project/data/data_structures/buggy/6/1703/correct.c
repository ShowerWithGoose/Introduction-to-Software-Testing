#include<stdio.h>
#include<stdlib.h>
typedef struct 
{
    int data[100];
    int top;
}Stack;
void initStack(Stack* s)
{
    s->top=-1;
}
int isFull(Stack* s)
{
    return s->top==100-1;
}
int isEmpty(Stack* s)
{
    return s->top==-1;
}
int pushStack(Stack* s,int item)
{
    if(isFull(s)) return -1;
    else
    {
        s->data[++(s->top)]=item;
        return 1;
    }
}
int popStack(Stack* s)
{
    if(isEmpty(s)) return -1;
    else
    {
        return s->data[(s->top)--];
    }
}
int main()
{
    Stack s;
    initStack(&s);
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        if(n==-1) break;
        else
        {
            if(n==1)
            {
                int m;
                scanf("%d",&m);
                if(isFull(&s))  
                    printf("error ");
                else
                    pushStack(&s,m);
            }
            else if(n==0)
            {
                if(isEmpty(&s))
                    printf("error ");
                else
                    printf("%d ",popStack(&s));
            }
        }
    }
    return 0;
}
