# include <stdio.h>
# include <math.h>
# include <string.h>
# include<stdlib.h>
#include <ctype.h>
#define max  100
int Stack[max];
int Top;
void initStack()
{
    Top=-1;
} 
int isEmpty()
{
    return Top==-1;
}
int isFull()
{
    return Top==max-1;
}
void push(int s[],int item )
{
    if(isFull())
        printf("error ");
    else
        s[++Top]=item;    
}
int pop(int s[])
{
    if(isEmpty())
        printf("error ");
    else
    {
        printf("%d ",s[Top--]);
    }
       
}
int main()
{
    int op,item;
    initStack();
    while(scanf("%d",&op)!=-1)
    {
        if(op==1)
        {
            scanf("%d",&item);
            push(Stack,item);
        }
        else if(op==0)
        {
            pop(Stack);
        }
    }
    return 0;
}
