#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define maxsize 1000

int top=0; // @@ [The initial value of 'top' should be -1 to indicate an empty stack, not 0. With top=0, the first element is placed at index 0, but isEmpty() checks for top==-1, causing inconsistency.]
int stack[maxsize];


int isFull()
{
    return top==maxsize-1;
}

int isEmpty()
{
    return top==-1; // @@ [This logic assumes top=-1 means empty, but 'top' is initialized to 0 and incremented before storing, so after one push, top=1, and stack[0] holds the value. However, during pop, the code accesses stack[top] which would be stack[1] (uninitialized) instead of stack[top-1]. The indexing and top management are inconsistent.]
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
                printf("error %d ",a); // @@ [According to the problem, only "error " should be printed on overflow/underflow, not "error <value> ". This extra %d causes wrong output format.]
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
                printf("%d ",stack[top]); // @@ [When popping, it should print stack[top-1], because 'top' points to the next available slot (not the current top element). Since top was incremented after push, the last element is at top-1. Accessing stack[top] reads an uninitialized or out-of-bound value.]
                stack[top]=0;
                top--;
            }
        }
        else if(order == -1) // @@ [The loop condition does not break on reading -1. The input ends with -1, but the program continues processing until scanf fails. Thus, -1 is not handled as a termination signal, leading to infinite loop or incorrect behavior.]
        {
            break;
        }
    }
    
    return 0;
}