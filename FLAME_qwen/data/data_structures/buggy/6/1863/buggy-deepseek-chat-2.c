#include <stdio.h>
int stack[100];
int top=-1;
int main()
{
    int op,t;
    while(scanf("%d",&op)!=EOF)
    {
        if(op==1)
        {
            if(top<=98) // @@ Error: The condition should be top < 99 (or top <= 98) to check if the stack is full, but the stack size is 100 (indices 0-99). When top is 98, the next push would go to index 99, which is valid. However, when top is 99, the stack is full, so the condition should be top < 99. The current condition allows pushing when top is 99, causing an out-of-bounds access.
            {
                scanf("%d",&stack[top+1]);
                top++;
            }
            else
            {
                scanf("%d",&t);
                printf("error"); // @@ Error: Missing space after "error" as required by the output format. Should be "error ".
            }
        }
        if(op==0)
            if(top>=0)
            {
                printf("%d",stack[top]); // @@ Error: Missing space after the popped element. Should be "%d " to match the required output format.
                top--;
            }
            else
            {
                printf("error"); // @@ Error: Missing space after "error" as required by the output format. Should be "error ".
            }
        if(op==-1)
            break;
    }
    return 0;
}