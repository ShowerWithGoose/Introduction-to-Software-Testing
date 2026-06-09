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
                scanf("%d",&stack[top+1]); // @@ [Error: When top is -1 (empty stack), top+1 is 0, which is correct. However, the condition top<=98 is incorrect because it allows pushing when top is 98, but after push top becomes 99, which is the last valid index (max capacity 100). The condition should be top<=98 to allow push when top is 98, but the issue is that the condition should be top<99 to allow push when top is 98 (since after push top becomes 99). Actually, the condition top<=98 is correct for a 100-element stack (indices 0-99), because when top is 98, top+1 is 99, which is valid. However, the problem states max capacity 100, so top should be < 99 to push. The condition top<=98 is equivalent to top<99, so this is correct. The real error is in the pop operation below.]
                top++;
            }
            else
            {
                scanf("%d",&t);
                printf("error"); // @@ [Error: Missing space after "error". The expected output requires a space after "error". Should be printf("error ");]
            }
        }
        if(op==0)
            if(top>=0)
            {
                printf("%d",stack[top]); // @@ [Error: Missing space after the popped element. The expected output requires a space after each popped element. Should be printf("%d ",stack[top]);]
                top--;
            }
            else
            {
                printf("error"); // @@ [Error: Missing space after "error". Should be printf("error ");]
            }
        if(op==-1)
            break;
    }
    return 0;
}