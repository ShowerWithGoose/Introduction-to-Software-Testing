#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define maxsize 1000

int top=0;
int stack[maxsize];


int isFull()
{
    return top==maxsize-1;
}

int isEmpty()
{
    return top==-1; // @@ [The initial value of 'top' is 0, so an empty stack should have top == -1, but push starts at index 0. However, this causes inconsistency: after first push, top becomes 1, and stack[0] holds the value. But during pop, code accesses stack[top] which would be stack[1] (uninitialized) instead of stack[top-1]. Also, isEmpty() returns true only if top==-1, but top starts at 0 and never goes to -1 unless decremented below 0. This logic mismatch leads to incorrect pop behavior and potential "error" misreporting.]
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
                printf("error %d ",a); // @@ [According to problem description, when a push fails due to full stack, only "error " (with space) should be printed, not "error <value> ". This extra %d and value violates output format.]
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
                printf("%d ",stack[top]); // @@ [After pushing, 'top' points to the next available index, so the top element is at stack[top-1], not stack[top]. Accessing stack[top] reads an uninitialized or out-of-bound value, leading to incorrect output.]
                stack[top]=0;
                top--; // @@ [Decrementing after accessing wrong index compounds the error. Should access stack[top-1], print it, then do top--.]
            }
        }
    }
    
    return 0;
}