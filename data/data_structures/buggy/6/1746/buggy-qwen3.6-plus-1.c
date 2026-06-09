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
            if(top==99) // @@ The condition should be top==100 to correctly check if the stack is full (max capacity 100). Currently, it incorrectly triggers an error when 99 elements are present, preventing the 100th push.
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
                printf("%d ",stack[top]); // @@ top represents the number of elements, so the top element is at index top-1. Accessing stack[top] is out of bounds. It should be stack[top-1].
                top--; 
            }
        }
        else if(op==-1)
        break;
    }
    return 0;
}