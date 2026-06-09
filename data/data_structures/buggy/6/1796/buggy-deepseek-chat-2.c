#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define maxsize 1000

int top=0; // @@ Error: top should be initialized to -1 to indicate an empty stack, not 0.
int stack[maxsize];


int isFull()
{
    return top==maxsize-1; // @@ Error: Since top is the index of the next free slot, the condition should be top == maxsize.
}

int isEmpty()
{
    return top==-1; // @@ Error: This will never be true because top is initialized to 0 and never set to -1. Should be top == 0.
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
                printf("error %d ",a); // @@ Error: The problem requires outputting only "error " (with a space), not the value a.
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
                printf("%d ",stack[top]); // @@ Error: Should print stack[top-1] because top is the index of the next free slot.
                stack[top]=0; // @@ Error: This line is unnecessary and incorrect; it sets the wrong index to 0.
                top--;
            }
        }
    }
    
    return 0;
}