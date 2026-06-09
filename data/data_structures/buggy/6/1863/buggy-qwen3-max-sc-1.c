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
            if(top<=98)
            {
                scanf("%d",&stack[top+1]);
                top++;
            }
            else
            {
                scanf("%d",&t);
                printf("error "); // @@ [Missing space after "error" in other branches; also, should check for full stack as top == 99, not top <= 98 which allows pushing to index 99 (100 elements), exceeding capacity]
            }
        }
        if(op==0) // @@ [Should be 'else if' to avoid checking pop logic when op is 1 or -1; leads to unintended behavior when op is 1 or -1]
            if(top>=0)
            {
                printf("%d ",stack[top]); // @@ [Missing space after %d in output format; expected output requires space after each popped element]
                top--;
            }
            else
            {
                printf("error "); // @@ [Missing space after "error"; output format requires a space after every output token]
            }
        if(op==-1) // @@ [Should be 'else if' to prevent unnecessary checks after handling op == 1 or op == 0]
            break;
    }
    return 0;
}