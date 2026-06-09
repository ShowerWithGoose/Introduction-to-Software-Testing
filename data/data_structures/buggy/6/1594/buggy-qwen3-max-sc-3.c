#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
typedef int ElemType;
ElemType Stack[MAXSIZE];
int top=-1;

void push(ElemType s[], ElemType item);
void pop(ElemType s[]);

void Error(char s[]); @@ // The Error function uses puts(), which appends a newline, but the problem requires output without extra newlines and with space separation. This causes formatting errors.

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
        Error("error "); @@ // Using puts("error ") prints "error \n", adding an unwanted newline instead of just "error ".
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
        Error("error "); @@ // Same issue: puts() adds a newline, violating output format.
    }
    else
    {
        printf("%d ",s[top]);
        top--;
    }
}

void Error(char s[])
{
    puts(s); @@ // puts() automatically appends a newline ('\n'), but expected output must be space-separated on one line without extra newlines.
}
int isFull()
{
    return top==MAXSIZE-1;
}
int isEmpty()
{
    return top==-1;
}