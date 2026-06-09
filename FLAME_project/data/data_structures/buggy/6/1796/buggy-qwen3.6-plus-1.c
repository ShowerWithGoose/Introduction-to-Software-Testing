#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define maxsize 1000

int top=0; // @@ The initial value of top should be -1 to represent an empty stack, because the current implementation uses top as the index of the next available slot (post-increment style for push), but isEmpty checks for -1. If top starts at 0, isEmpty (top==-1) will never be true initially, but more importantly, the pop logic is flawed relative to this top definition.
int stack[maxsize];


int isFull()
{
    return top==maxsize-1;
}

int isEmpty()
{
    return top==-1; // @@ This check is inconsistent with top initialized to 0. If top represents the count or next index, empty should be top==0. If top represents the index of the top element, it should start at -1. Given the push/pop logic below, top acts as "next free index". So isEmpty should be top==0.
}
int main()
{
    int order,a;
    while(scanf("%d",&order)!=-1)
    {
        if(order==1)
        {
            scanf("%d",&a);
            if(isFull())
            {
                printf("error %d ",a);
            }
            else
                {
                    stack[top]=a;
                    top++;
                }
        }
        else if(order==0)
        {
            if(isEmpty())
            {
               printf("error ");
            }
            else
            {
                printf("%d ",stack[top]); // @@ Error: top points to the next free location (due to push doing stack[top]=a; top++). The actual top element is at stack[top-1]. Accessing stack[top] reads uninitialized or wrong data.
                stack[top]=0;
                top--;
            }
        }
    }
    
    return 0;
}