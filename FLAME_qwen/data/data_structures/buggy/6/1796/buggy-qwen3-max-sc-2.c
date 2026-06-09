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
    return top==-1; // @@ [The initial value of 'top' is 0, so an empty stack should be indicated by top == 0, not top == -1. This causes incorrect detection of empty stack.]
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
                printf("error %d ",a); // @@ [According to the problem, only "error " (without the number) should be printed on push/pop failure. Printing the number 'a' is incorrect.]
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
                printf("%d ",stack[top]); // @@ [After pushing, 'top' points to the next available slot, so the top element is at index 'top - 1', not 'top'. This accesses an uninitialized or out-of-bound element.]
                stack[top]=0;
                top--;
            }
        }
    }
    
    return 0;
}