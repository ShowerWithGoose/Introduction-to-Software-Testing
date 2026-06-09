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
                printf("error"); // @@ The error message should be "error " (with a trailing space) to match the expected output format.
            }
        }
        if(op==0)
            if(top>=0)
            {
                printf("%d",stack[top]); // @@ The popped element should be followed by a space (" %d" or "%d ") to match the expected output format where elements are separated by spaces.
                top--;
            }
            else
            {
                printf("error"); // @@ The error message should be "error " (with a trailing space) to match the expected output format.
            }
        if(op==-1)
            break;
    }
    return 0;
}