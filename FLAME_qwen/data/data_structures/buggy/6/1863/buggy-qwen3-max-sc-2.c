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
                printf("error "); // @@ [Missing space after "error" in push error case; expected output format requires a space after each output token including "error"]
            }
        }
        if(op==0)
            if(top>=0)
            {
                printf("%d ",stack[top]); // @@ [Missing space after popped value; output format requires space after each element]
                top--;
            }
            else
            {
                printf("error "); // @@ [Missing space after "error" in pop error case; output format requires a space after each output token including "error"]
            }
        if(op==-1)
            break;
    }
    return 0;
}