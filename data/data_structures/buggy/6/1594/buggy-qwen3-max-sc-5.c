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
        Error("error "); @@ // The Error function uses puts(), which appends a newline. The problem requires output with a space and no newline.
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
        Error("error "); @@ // The Error function uses puts(), which appends a newline. The problem requires output with a space and no newline.
    }
    else
    {
        printf("%d ",s[top]);
        top--;
    }
}

void Error(char s[])
{
    puts(s); @@ // puts() adds a newline ('\n') after the string, but the expected output format requires only a space and no newline.
}
int isFull()
{
    return top==MAXSIZE-1;
}
int isEmpty()
{
    return top==-1;
}