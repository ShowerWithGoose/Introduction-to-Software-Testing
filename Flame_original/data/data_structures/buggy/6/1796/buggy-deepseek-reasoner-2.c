#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define maxsize 1000 // @@ [Problem specifies max capacity 100, but this uses 1000. May cause logical mismatch in test cases.]
int top=0; // @@ [Initializing top to 0 is non-standard. With this implementation, top should represent the next free index. This works, but the isEmpty and isFull conditions below are inconsistent with this choice.]
int stack[maxsize];


int isFull()
{
    return top==maxsize-1; // @@ [Wrong condition. Since top points to next free slot, the stack is full when top == maxsize, not maxsize-1.]
}

int isEmpty()
{
    return top==-1; // @@ [Wrong condition. top is never -1 because it starts at 0, so isEmpty always returns false. Should be top==0.]
}
int main()
{
    int order,a;
    while(scanf("%d",&order)!=-1) // @@ [Does not stop when order == -1 as required. Should break on -1 to end operations.]
    {
        if(order==1)
        {
            scanf("%d",&a);
            if(isFull())
            {
                printf("error %d ",a); // @@ [Should only print "error " without the value. The specification says output "error" followed by a space.]
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
                printf("%d ",stack[top]); // @@ [Incorrect index. top points to the next free slot, so the top element is at stack[top-1].]
                stack[top]=0;
                top--;
            }
        }
    }
    
    return 0;
}