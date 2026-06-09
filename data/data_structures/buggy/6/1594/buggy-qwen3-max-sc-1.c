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
        Error("error "); @@ [The Error function uses puts() which appends a newline, but the problem requires output without extra newlines and with a space after each "error". This causes formatting mismatch.]
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
        Error("error "); @@ [Same issue: puts() adds a newline, but expected output should be space-separated on one line without extra newlines.]
    }
    else
    {
        printf("%d ",s[top]);
        top--;
    }
}

void Error(char s[])
{
    puts(s); @@ [puts() outputs the string followed by a newline ('\n'), but the problem expects all output on a single line with space separation. Should use printf("%s", s) or fputs(s, stdout).]
}
int isFull()
{
    return top==MAXSIZE-1;
}
int isEmpty()
{
    return top==-1;
}