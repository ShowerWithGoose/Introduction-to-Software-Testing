#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
int stack[110];
int main()
{
    int top=0;
    int op,num;
    while(1)
    {
        scanf("%d",&op);
        if(op==1)
        {
            scanf("%d",&num);
            if(top==99) // @@ The maximum capacity is 100, so the stack is full when top equals 100. Checking top == 99 incorrectly limits the capacity to 99.
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
                printf("%d ",stack[top]); // @@ Since top is incremented after each push, it points to the next empty slot. The actual top element is at stack[top-1], so accessing stack[top] reads an uninitialized/garbage value.
                top--; 
            }
        }
        else if(op==-1)
        break;
    }
    return 0;
}