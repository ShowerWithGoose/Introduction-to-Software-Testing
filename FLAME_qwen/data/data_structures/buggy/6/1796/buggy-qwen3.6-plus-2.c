#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define maxsize 1000 // @@ The problem specifies a maximum capacity of 100, not 1000.

int top=0;
int stack[maxsize];


int isFull()
{
    return top==maxsize-1; // @@ Since top points to the next free slot, the stack is full when top == maxsize.
}

int isEmpty()
{
    return top==-1; // @@ top is initialized to 0 and represents the next free slot, so the empty condition should be top == 0.
}
int main()
{
    int order,a;
    while(scanf("%d",&order)!=-1) // @@ The loop does not break when order == -1 as required by the problem statement.
    {
        if(order==1)
        {
            scanf("%d",&a);
            if(isFull())
            {
                printf("error %d ",a); // @@ The problem requires printing only "error " when the stack is full, not the value.
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
                printf("%d ",stack[top]); // @@ top points to the next free slot, so the top element is at index top-1.
                stack[top]=0;
                top--;
            }
        }
    }
    
    return 0;
}