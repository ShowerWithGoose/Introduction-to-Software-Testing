#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define maxsize 1000

int top=0; // @@ [The initial value of 'top' should be -1 to indicate an empty stack, not 0. With top=0, the first element is placed at index 0 but isEmpty() checks for top==-1, causing inconsistency.]
int stack[maxsize];


int isFull()
{
    return top==maxsize-1;
}

int isEmpty()
{
    return top==-1; // @@ [This logic assumes top=-1 means empty, but 'top' is initialized to 0 and incremented before storing, so after one push, top=1, and stack[0] holds the value. Thus, when stack has one element, top=1, and isEmpty() incorrectly returns false only when top==-1, but pop uses stack[top] which would be stack[1] — an uninitialized value. The indexing and top management are inconsistent.]
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
                printf("error %d ",a); // @@ [According to the problem, only "error " (without the number) should be printed on overflow or underflow. Printing the number 'a' here is incorrect.]
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
                printf("%d ",stack[top]); // @@ [When popping, the top element is at index 'top-1', not 'top', because 'top' points to the next available slot. So accessing stack[top] reads an uninitialized or out-of-bound value. It should be stack[top-1].]
                stack[top]=0;
                top--;
            }
        }
        else if(order == -1) // @@ [The loop condition is while(scanf(...) != -1), which does not break on reading -1. The program never stops reading input upon encountering -1, leading to infinite loop or undefined behavior. The problem states that -1 marks end of operations, so the loop must break when order == -1.]
        {
            break;
        }
    }
    
    return 0;
}