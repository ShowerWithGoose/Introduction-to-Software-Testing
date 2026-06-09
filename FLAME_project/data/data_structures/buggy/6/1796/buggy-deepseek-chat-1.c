#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define maxsize 1000

int top=0; // @@ [Error: top should be initialized to -1 to represent an empty stack, not 0. With top=0, the stack appears to have one element initially, causing incorrect behavior for isEmpty() and push/pop operations.]
int stack[maxsize];


int isFull()
{
    return top==maxsize-1;
}

int isEmpty()
{
    return top==-1; // @@ [Error: Since top is initialized to 0, this condition will never be true when the stack is actually empty. The stack is empty when top==0, but this function checks for top==-1, so it will incorrectly report the stack as not empty.]
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
                printf("error %d ",a); // @@ [Error: According to the problem, when a push fails due to full stack, only "error " should be printed, not the value being pushed. The output should be "error " without the number.]
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
                printf("%d ",stack[top]); // @@ [Error: When popping, the element at index top-1 should be printed, not stack[top], because top points to the next empty slot. After pushing, top is incremented, so the last pushed element is at top-1. This causes the wrong value to be printed.]
                stack[top]=0;
                top--;
            }
        }
    }
    
    return 0;
}