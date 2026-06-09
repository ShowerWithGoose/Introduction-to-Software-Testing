#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
typedef int ElemType;
ElemType Stack[MAXSIZE];
int top=-1;

void push(ElemType s[], ElemType item);
void pop(ElemType s[]);

void Error(char s[]);

int isFull();
int isEmpty();
int main()
{
    int op;    
    int input;

    while(scanf("%d",&op)!=-1)
    {
        if(op==1)
        {
            scanf("%d",&input);
            push(Stack,input);
            
        }
        else if(op==0)
        {
            pop(Stack);
            
        }
        else
        {
            return 0;
        }
    }
    
    return 0;
    
}
void push(ElemType s[], ElemType item)
{
    if (isFull())
    {
        Error("error ");
    }
    else
    {
        s[++top]=item;
    }
}
void pop(ElemType s[])
{
    if(isEmpty())
    {
        Error("error ");
    }
    else
    {
        printf("%d ",s[top]);
        top--;
    }
}

void Error(char s[])
{
    puts(s); // @@ puts() automatically appends a newline character, which violates the output format requirement of printing "error " followed by a space without a newline. It should use printf("%s", s) or fputs(s, stdout) instead.
}
int isFull()
{
    return top==MAXSIZE-1;
}
int isEmpty()
{
    return top==-1;
}