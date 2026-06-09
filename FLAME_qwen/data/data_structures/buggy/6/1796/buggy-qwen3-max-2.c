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
    return top==-1; // @@ [The initial value of 'top' is 0, so an empty stack should have top == -1, but push starts at index 0. However, the isEmpty() logic assumes top starts at -1, which contradicts the initialization 'int top=0;'. This causes isEmpty() to incorrectly return false when the stack is actually empty (top=0).]
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
                printf("error %d ",a); // @@ [According to the problem, only "error " should be printed on overflow, not "error <value> ". This prints extra value 'a', which is incorrect.]
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
                printf("%d ",stack[top]); // @@ [When popping, the top element is at index 'top-1', not 'top', because 'top' points to the next available slot. Accessing stack[top] reads an uninitialized or already popped value.]
                stack[top]=0;
                top--;
            }
        }
    }
    
    return 0;
}