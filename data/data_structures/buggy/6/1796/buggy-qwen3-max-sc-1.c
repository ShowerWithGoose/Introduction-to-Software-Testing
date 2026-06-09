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
    return top==-1; // @@ [The initial value of 'top' is 0, so an empty stack should be 'top == 0', not 'top == -1'. This causes incorrect detection of empty stack.]
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
                printf("error %d ",a); // @@ [According to the problem, only "error " should be printed on overflow, not "error <value> ".]
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
                printf("%d ",stack[top]); // @@ [After pushing, 'top' points to the next empty slot, so the top element is at 'stack[top - 1]', not 'stack[top]'. This accesses an uninitialized or out-of-bound element.]
                stack[top]=0;
                top--;
            }
        }
    }
    
    return 0;
}