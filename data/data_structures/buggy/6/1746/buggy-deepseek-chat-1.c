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
            if(top==99) // @@ Error: The stack capacity is 110, but the condition checks for top==99, which incorrectly limits the stack to 100 elements (indices 0-99). The correct check should be top==110 to match the array size, or top==100 to match the problem's maximum capacity of 100.
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
                printf("%d ",stack[top]); // @@ Error: When popping, the current top index points to the next empty slot (since top is incremented after push). The correct element to pop is at stack[top-1], so this should be stack[top-1] or top should be decremented before accessing.
                top--; 
            }
        }
        else if(op==-1)
        break;
    }
    return 0;
}