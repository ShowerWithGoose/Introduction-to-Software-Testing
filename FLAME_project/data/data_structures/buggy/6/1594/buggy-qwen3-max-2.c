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

    while(scanf("%d",&op)!=-1) // @@ [The loop condition should check for EOF, not -1. When scanf fails (e.g., at end of input), it returns EOF, not -1. This causes the loop to not terminate properly when -1 is read as an operation, because op becomes -1 and the loop condition evaluates to false (since scanf returns 1 on successful read of -1), but then the else clause handles -1 correctly. However, the real issue is that after reading -1, the program exits, so this may not be the main bug. The actual critical bug is in the Error function using puts(), which appends a newline.]
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
    puts(s); // @@ [Using puts() prints the string followed by a newline ('\n'), but the expected output requires only a space after "error", with all output on a single line. This causes a newline to be inserted, breaking the output format. It should use printf("%s", s) or similar without adding a newline.]
}
int isFull()
{
    return top==MAXSIZE-1;
}
int isEmpty()
{
    return top==-1;
}