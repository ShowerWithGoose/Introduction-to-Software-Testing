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
                printf("error "); // @@ [Missing space after "error" in output; expected format requires a space after each output item including "error"]
            }
        }
        if(op==0) // @@ [Should be 'else if' to avoid unintended execution after op==1 or op==-1; current code may execute multiple blocks for one op]
            if(top>=0)
            {
                printf("%d ",stack[top]); // @@ [Missing space after %d in output; expected format requires space after each popped element]
                top--;
            }
            else
            {
                printf("error "); // @@ [Missing space after "error" in output; expected format requires a space after each output item including "error"]
            }
        if(op==-1) // @@ [Should be 'else if' to avoid unintended execution after op==1 or op==0; current code may execute multiple blocks for one op]
            break;
    }
    return 0;
}