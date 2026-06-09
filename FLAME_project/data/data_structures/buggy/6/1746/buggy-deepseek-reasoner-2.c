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
            if(top==99) // @@ [off-by-one error; should be if(top==100) because with top=0 initially the stack is full after 100 pushes (top becomes 100)]
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
                printf("%d ",stack[top]); // @@ [prints uninitialized element; should print stack[top-1] after decrementing top, because top points to next free slot]
                top--; // @@ [decrement should occur before printing to correctly access the top element]
            }
        }
        else if(op==-1)
        break;
    }
    return 0;
}