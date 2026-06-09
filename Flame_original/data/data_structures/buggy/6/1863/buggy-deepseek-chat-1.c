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
            if(top<=98) // @@ Error: The condition should be top < 99 (or top <= 98) to check if the stack is full, but the stack size is 100 (indices 0-99). When top is 98, the next push would go to index 99, which is valid. The condition should be top < 99 to allow push when top is 98. However, the reference program uses top==100 as full condition, but here the array size is 100, so top can go up to 99. The condition top<=98 incorrectly prevents push when top is 98 (which should be allowed). Also, the reference program checks top==100, but here the array is size 100, so the correct full check should be top >= 99.
            {
                scanf("%d",&stack[top+1]);
                top++;
            }
            else
            {
                scanf("%d",&t);
                printf("error"); // @@ Error: Missing space after "error". The problem requires "error " (with a trailing space) for error output.
            }
        }
        if(op==0) // @@ Error: Should use else if to avoid checking op==0 when op==1 was already handled. This could cause issues if op is 1 and then also checks op==0.
            if(top>=0)
            {
                printf("%d",stack[top]); // @@ Error: Missing space after the popped element. The problem requires each popped element to be followed by a space.
                top--;
            }
            else
            {
                printf("error"); // @@ Error: Missing space after "error". The problem requires "error " (with a trailing space) for error output.
            }
        if(op==-1)
            break;
    }
    return 0;
}