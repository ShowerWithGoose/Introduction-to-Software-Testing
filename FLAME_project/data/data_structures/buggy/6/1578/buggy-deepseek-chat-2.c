#include <stdio.h>
#define MAXSIZE 100
typedef int elemtype;
int STACK[MAXSIZE];
elemtype top=-1;
int isfull()
{
    return top==MAXSIZE-1;
}
int isempty()
{
    return top==-1;
}
void push(elemtype s[],elemtype item)
{
    if(isfull())
    {
        printf("error ");
    }
    else
    {
        s[++top]=item;
    }
}
void pop(int s[])
{
    if(isempty())
    {
        printf("error ");
    }
    else
    {
        printf("%d ,s[top--]"); // @@ The format string is incorrect; it prints the literal text ",s[top--]" instead of the popped value. Should be printf("%d ", s[top--]);
    }
}
int main()
{
    int i,op,input;
    for(i=0;;i++)//构造无限循环，除非遇到-1
    {
        scanf("%d ",&op); // @@ The space after %d causes the program to wait for non-whitespace input, leading to incorrect reading. Should be scanf("%d",&op);
        if(op==1)//入栈
        {
            scanf("%d ",&input); // @@ Same issue: the space after %d causes incorrect input reading. Should be scanf("%d",&input);
            push(STACK,input);
        }
        else if(op==0)//出栈
        {
            pop(STACK);
        }
        else if(op==-1)//stop
        {
            break;
        }
    }    
    return 0;
}