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
        printf("%d ,s[top--]"); // @@ [The format string is incorrect. It should be "%d " and the expression s[top--] should be outside the quotes as an argument to printf. As written, it prints the literal string ",s[top--]" instead of the popped value.]
    }
}
int main()
{
    int i,op,input;
    for(i=0;;i++)//构造无限循环，除非遇到-1
    {
        scanf("%d ",&op); // @@ [Using " %d " with a trailing space in scanf can cause unexpected blocking behavior because it waits for non-whitespace input after the integer. This may lead to issues in reading the next operation correctly, especially at the end of input.]
        if(op==1)//入栈
        {
            scanf("%d ",&input); // @@ [Same issue as above: trailing space in format string may cause scanf to wait for additional non-whitespace input unnecessarily.]
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