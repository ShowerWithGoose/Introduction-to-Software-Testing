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
                printf("error"); // @@ Missing space after "error" as required by the output format.
            }
        }
        if(op==0)
            if(top>=0)
            {
                printf("%d",stack[top]); // @@ Missing space after the popped element as required by the output format.
                top--;
            }
            else
            {
                printf("error"); // @@ Missing space after "error" as required by the output format.
            }
        if(op==-1)
            break;
    }
    return 0;
}