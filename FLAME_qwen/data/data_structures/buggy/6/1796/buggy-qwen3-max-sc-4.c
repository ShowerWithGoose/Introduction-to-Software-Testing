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
    return top==-1; // @@ [The initial value of 'top' is 0, so an empty stack should have top == -1, but push starts at index 0. However, the isEmpty() logic assumes top starts at -1, which contradicts the initialization 'int top=0;'. This inconsistency causes incorrect empty check.]
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
                printf("error %d ",a); // @@ [According to the problem, when a push fails due to full stack, only "error " should be printed, not "error <value> ".]
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
                printf("%d ",stack[top]); // @@ [After pushing, 'top' points to the next empty slot. So the top element is at 'top-1', not 'top'. This accesses an uninitialized or out-of-bound element.]
                stack[top]=0;
                top--;
            }
        }
    }
    
    return 0;
}