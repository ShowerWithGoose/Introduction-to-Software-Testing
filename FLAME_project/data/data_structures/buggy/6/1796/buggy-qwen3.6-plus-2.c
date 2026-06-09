#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define maxsize 1000

int top=0; // @@ The initial value of top should be -1 to represent an empty stack, because the code uses stack[top] before incrementing or after decrementing in a way that assumes top points to the current element or the next free slot inconsistently. Specifically, isEmpty checks for -1, but top is initialized to 0.
int stack[maxsize];


int isFull()
{
    return top==maxsize-1;
}

int isEmpty()
{
    return top==-1;
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
                printf("%d ",stack[top]); // @@ Logic error: top points to the next empty slot (since push does stack[top]=a; top++). To pop the last inserted element, we must access stack[top-1]. Accessing stack[top] reads uninitialized memory or the wrong element.
                stack[top]=0;
                top--;
            }
        }
    }
    
    return 0;
}