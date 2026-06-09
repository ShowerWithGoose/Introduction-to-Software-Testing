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
        printf("%d ,s[top--]"); // @@ Incorrect printf syntax: missing comma between format string and argument, and misplaced quotes. It should be printf("%d ", s[top--]); to correctly print the popped element.
    }
}
int main()
{
    int i,op,input;
    for(i=0;;i++)//构造无限循环，除非遇到-1
    {
        scanf("%d ",&op); // @@ Trailing space in scanf format string causes it to wait for non-whitespace input after reading the integer, which may cause the program to hang or fail on certain inputs. Should be scanf("%d", &op);
        if(op==1)//入栈
        {
            scanf("%d ",&input); // @@ Trailing space in scanf format string causes it to wait for additional input. Should be scanf("%d", &input);
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