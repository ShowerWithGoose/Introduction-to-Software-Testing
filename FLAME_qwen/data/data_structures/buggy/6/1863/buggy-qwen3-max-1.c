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
        if(op==0) // @@ [Should be 'else if' to avoid unintended execution after op==1 or op==-1; current structure may cause multiple condition checks per iteration]
            if(top>=0)
            {
                printf("%d ",stack[top]); // @@ [Missing space after "%d" in original code; output format requires space after each popped element]
                top--;
            }
            else
            {
                printf("error "); // @@ [Missing space after "error" in original code; expected output format requires a space after each output including "error"]
            }
        if(op==-1) // @@ [Should be 'else if' to maintain exclusive condition handling; though break works, it's logically inconsistent with intended operation separation]
            break;
    }
    return 0;
}