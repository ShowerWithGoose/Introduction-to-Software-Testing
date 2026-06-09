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
                printf("%d ",stack[top]); // @@ [When popping, the top index points to the next available slot, so the actual top element is at stack[top-1]. Accessing stack[top] reads an uninitialized or out-of-bound value.]
                top--; 
            }
        }
        else if(op==-1)
        break;
    }
    return 0;
}