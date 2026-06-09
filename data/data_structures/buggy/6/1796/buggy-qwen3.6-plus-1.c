#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define maxsize 1000 // @@ [The maximum capacity should be 100 as per the problem description]

int top=0;
int stack[maxsize];


int isFull()
{
    return top==maxsize-1; // @@ [Incorrect full condition; since top tracks the next free index, it should be top==maxsize]
}

int isEmpty()
{
    return top==-1; // @@ [Incorrect empty condition; since top starts at 0 and tracks the next free index, it should be top==0]
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
                printf("error %d ",a); // @@ [Should only print "error " without the pushed value, as specified]
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
                printf("%d ",stack[top]); // @@ [Prints the element at the next free index instead of the top element; should be stack[top-1]]
                stack[top]=0; // @@ [Unnecessary assignment that modifies the array; popping should only decrement top]
                top--;
            }
        }
    }
    
    return 0;
}