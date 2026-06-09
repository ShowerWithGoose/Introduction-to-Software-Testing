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
    return top==-1; // @@ [The initial value of 'top' is 0, so an empty stack should have top == -1, but push starts by assigning to stack[top] then incrementing. This causes inconsistency: after first push, top becomes 1, but element is at index 0. During pop, it accesses stack[top] which is one past the last valid element.]
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
                printf("error %d ",a); // @@ [According to problem description, only "error " (without the number) should be printed on overflow/underflow. Printing the number 'a' here is incorrect.]
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
                printf("%d ",stack[top]); // @@ [After pushing, 'top' points to the next available slot, so the top element is at stack[top-1], not stack[top]. Accessing stack[top] reads an uninitialized or out-of-bound value.]
                stack[top]=0;
                top--;
            }
        }
    }
    
    return 0;
}