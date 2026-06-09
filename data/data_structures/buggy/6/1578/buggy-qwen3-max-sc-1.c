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
        printf("%d ,s[top--]"); // @@ [The format string is incorrect: it prints the literal string ",s[top--]" instead of the value. It should be `printf("%d ", s[top--]);`]
    }
}
int main()
{
    int i,op,input;
    for(i=0;;i++)//构造无限循环，除非遇到-1
    {
        scanf("%d ",&op); // @@ [The space after %d in scanf can cause unexpected behavior by consuming extra whitespace and potentially waiting for more input; it should be `scanf("%d", &op);`]
        if(op==1)//入栈
        {
            scanf("%d ",&input); // @@ [Same issue: trailing space in format string may cause input reading problems; should be `scanf("%d", &input);`]
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