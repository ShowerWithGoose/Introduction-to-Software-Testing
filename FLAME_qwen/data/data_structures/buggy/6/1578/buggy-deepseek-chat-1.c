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
        printf("%d ,s[top--]"); // @@ Error: The format string is incorrect. It should be printf("%d ",s[top--]); to print the popped element and then decrement top. The current code prints the literal string ",s[top--]" instead of the value.
    }
}
int main()
{
    int i,op,input;
    for(i=0;;i++)//构造无限循环，除非遇到-1
    {
        scanf("%d ",&op); // @@ Error: The format string "%d " has a trailing space, which will cause scanf to consume any whitespace after the integer, potentially causing issues with reading subsequent inputs. It should be "%d" without the space.
        if(op==1)//入栈
        {
            scanf("%d ",&input); // @@ Error: Same issue as above; the trailing space in "%d " can cause input reading problems. It should be "%d".
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