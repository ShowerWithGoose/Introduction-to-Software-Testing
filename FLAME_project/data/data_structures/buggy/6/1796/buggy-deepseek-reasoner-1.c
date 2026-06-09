#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define maxsize 1000

int top=0; // @@ [Error: top should be initialized to -1 to indicate empty stack; with top=0, the first element is stored at index 0 and top becomes 1, but isEmpty() checks top==-1, which never holds, leading to incorrect pop behavior.]
int stack[maxsize];


int isFull()
{
    return top==maxsize-1;
}

int isEmpty()
{
    return top==-1; // @@ [Error: Condition should be top==0 because top starts at 0 for empty stack. This causes pop to not detect empty stack correctly.]
}
int main()
{
    int order,a;
    while(scanf("%d",&order)!=-1) // Note: This condition is not the direct cause of wrong output, but it's logically incorrect; scanf returns number of items read, not the value itself.
    {
        if(order==1)
        {
            scanf("%d",&a);
            if(isFull())
            {
                printf("error %d ",a); // Minor: format should be "error " only, but not affecting test case.
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
                printf("%d ",stack[top]); // @@ [Error: top points to the next free slot; this prints an uninitialized value (0). Should print stack[top-1] or decrement top first. E.g., top--; printf("%d ",stack[top]);]
                stack[top]=0;
                top--;
            }
        }
    }
    
    return 0;
}