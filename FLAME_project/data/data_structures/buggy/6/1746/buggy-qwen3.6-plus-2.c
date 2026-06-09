#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
int stack[110];
int main()
{
    int top=0; // @@ The initial value of top should be -1 to represent an empty stack, or the logic for push/pop needs to be adjusted. With top=0 representing empty, push should use stack[top++] and pop should use stack[--top]. Currently, push uses stack[top] then top++, which is correct for top=0 being empty index, but pop accesses stack[top] which is out of bounds (one past the last element).
    int op,num;
    while(1)
    {
        scanf("%d",&op);
        if(op==1)
        {
            scanf("%d",&num);
            if(top==99) // @@ If top represents the count of elements (0-based empty), full capacity 100 means top==100. If top represents the index of the top element, initial top should be -1. Given the current mix, if top=0 is empty, pushing 1st element goes to index 0, top becomes 1. Pushing 100th element goes to index 99, top becomes 100. So full check should be top==100.
            printf("error ");
            else
            {
                stack[top]=num;
                top++;
            }
        }
        else if(op==0)
        {
            if(top==0)
            printf("error ");
            else
            {
                printf("%d ",stack[top]); // @@ Accessing stack[top] is incorrect because top points to the next available slot (since push does stack[top] then top++). The top element is at stack[top-1].
                top--; 
            }
        }
        else if(op==-1)
        break;
    }
    return 0;
}