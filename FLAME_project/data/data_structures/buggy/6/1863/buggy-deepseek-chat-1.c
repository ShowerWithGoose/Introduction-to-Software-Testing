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
            if(top<=98) // @@ Error: The condition should be top <= 99 to check if the stack is full (capacity 100, indices 0-99). Using top <= 98 incorrectly prevents pushing when top is 98 (stack has 99 elements), leaving one slot unused.
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
                printf("%d",stack[top]); // @@ Error: Missing space after the popped element. Should be "%d " to match the expected output format.
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