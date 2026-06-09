#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct stack
{
    int top;
    int data[100];
}stack;
int main()
{
    stack s;
    s.top=0;
    int op;
    while (scanf("%d",&op)!=EOF)
    {
        if(-1==op)
        break;
        else if(1==op)
        {
            if(s.top==100) // @@ Error: The stack capacity is 100, but valid indices are 0-99. When top is 100, the stack is full, but the condition should check if top == 100 to prevent overflow. However, the push operation uses s.data[s.top++] which will access index 100 when top is 100, causing out-of-bounds access. The correct check should be if(s.top >= 100) or if(s.top == 100) to avoid writing beyond the array.
            printf("error ");
            else
            scanf("%d",&s.data[s.top++]); // @@ Error: This line reads into s.data[s.top] and then increments top. However, if the stack is full (top == 100), this would write to s.data[100] which is out of bounds. The error check above should prevent this, but the condition is incorrect as noted.
        }
        else if(0==op)
        {
            if(s.top==0) // @@ Error: When top is 0, the stack is empty, so the condition is correct for detecting underflow. However, the pop operation uses --s.top which decrements top before accessing the element. When top is 0, --s.top becomes -1, and accessing s.data[-1] is out of bounds. The error check prevents this, but the logic is correct only if the check is accurate.
            printf("error ");
            else
            printf("%d",s.data[--s.top]); // @@ Error: This prints the popped element without a space after it, except for the last element. The problem requires a space after each output element, including the last one. Additionally, the pop operation decrements top before accessing, which is correct for a stack where top points to the next empty slot, but the output format is missing a trailing space.
        }
    }
    return 0;
}