#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define maxsize 1000

int top=0; // @@ top should be initialized to -1 to represent empty stack; otherwise isEmpty() never true.
int stack[maxsize];


int isFull()
{
    return top==maxsize-1; // @@ off-by-one: should be top==maxsize (since top is count of elements, not index)
}

int isEmpty()
{
    return top==-1; // @@ error: top starts at 0, so this condition is never true. Should return top==0.
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
                printf("error %d ",a); // @@ should only output "error " without the value.
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
                printf("%d ",stack[top]); // @@ should print stack[top-1] because top is the count of elements, not index of top element.
                stack[top]=0; // @@ unnecessary and incorrect; the element at stack[top] is garbage or out-of-bounds.
                top--;
            }
        }
    }
    
    return 0;
}