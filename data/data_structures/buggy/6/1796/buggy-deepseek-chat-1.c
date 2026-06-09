#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define maxsize 1000

int top=0; // @@ [Error: The initial value of top should be -1 to indicate an empty stack, not 0. With top=0, the stack appears to have one element, causing incorrect empty/full checks and pop operations.]
int stack[maxsize];


int isFull()
{
    return top==maxsize-1; // @@ [Error: Since top starts at 0, the full condition should be top==maxsize, not maxsize-1, to correctly reflect the number of elements pushed.]
}

int isEmpty()
{
    return top==-1; // @@ [Error: With top initialized to 0, this condition will never be true, so the stack will never be detected as empty, causing pop operations on an empty stack to not print "error".]
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
                printf("error %d ",a); // @@ [Error: The output format is incorrect. According to the problem, when a push fails due to a full stack, only "error " should be printed, not "error %d ".]
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
                printf("%d ",stack[top]); // @@ [Error: When popping, the element at index top-1 should be returned, not stack[top], because top points to the next empty slot after the last element.]
                stack[top]=0;
                top--;
            }
        }
    }
    
    return 0;
}