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
            if(top==99)
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
                printf("%d ",stack[top]); // @@ Error: When top is the index of the next empty slot, the top element is at stack[top-1], not stack[top]. This prints the wrong value (uninitialized or stale data) instead of the actual top element.
                top--; 
            }
        }
        else if(op==-1)
        break;
    }
    return 0;
}