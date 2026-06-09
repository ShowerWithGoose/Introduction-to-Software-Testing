#include <stdio.h>

int main()
{
    int stack[101];
    int cnt=0;

    int op;
    int value;
    while(scanf("%d",&op),op!=-1)
    {
        if(op==1)
        {
            scanf("%d",&value);
            if(cnt==100)
            {
                printf("error ");
            }
            else
            {
                stack[cnt++]=value;
            }
        }
        else if(op==0)
        {
            if(cnt==0)
            {
                printf("error ");
            }
            else
            {
                printf("%d",stack[--cnt]); // @@ Missing space after the popped element. The expected output requires a space after each popped element, but this code prints the number without a trailing space, causing all outputs to be concatenated.
            }
        }
    }
    return 0;
}