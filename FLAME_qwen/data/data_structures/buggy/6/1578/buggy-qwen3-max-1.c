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
        printf("%d ,s[top--]"); // @@ [The format string is incorrect: it prints literal ",s[top--]" instead of the value. It should be printf("%d ", s[top--]);]
    }
}
int main()
{
    int i,op,input;
    for(i=0;;i++)//构造无限循环，除非遇到-1
    {
        scanf("%d ",&op); // @@ [The space after %d in scanf can cause unexpected blocking or skipping of input; it's generally safer to use "%d" without trailing space unless necessary. However, the main error is in pop function.]
        if(op==1)//入栈
        {
            scanf("%d ",&input); // @@ [Same issue with trailing space in format string; may interfere with input parsing, especially near end-of-input or when reading -1.]
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