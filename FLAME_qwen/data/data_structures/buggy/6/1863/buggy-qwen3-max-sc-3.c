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
                printf("error "); // @@ [Missing space after "error" in original code; expected output format requires a space after each output including "error"]
            }
        }
        if(op==0) // @@ [Should be 'else if' to avoid checking pop logic after push or end operations; current code may execute multiple operation blocks for one input]
            if(top>=0)
            {
                printf("%d ",stack[top]); // @@ [Missing space after %d in original code; output format requires space after each popped element]
                top--;
            }
            else
            {
                printf("error "); // @@ [Missing space after "error" in original code; expected output format requires a space after each output including "error"]
            }
        if(op==-1) // @@ [Should be 'else if' to prevent unnecessary checks after handling -1; also, break is used but loop condition may still read next input]
            break;
    }
    return 0;
}