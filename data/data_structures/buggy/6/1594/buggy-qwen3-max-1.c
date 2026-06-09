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
        Error("error "); @@ [The Error function uses puts(), which appends a newline. The problem requires output with a space and no extra newline. This causes formatting mismatch in output.]
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
        Error("error "); @@ [Same issue: puts() adds a newline, but expected output should be space-separated on one line without newlines after each "error".]
    }
    else
    {
        printf("%d ",s[top]);
        top--;
    }
}

void Error(char s[])
{
    puts(s); @@ [puts() automatically appends a newline ('\n'), which violates the required output format of space-separated tokens on a single line. Should use printf("%s", s) or similar.]
}
int isFull()
{
    return top==MAXSIZE-1;
}
int isEmpty()
{
    return top==-1;
}