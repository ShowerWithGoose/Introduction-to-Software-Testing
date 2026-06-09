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
                printf("%d",stack[--cnt]); // @@ Missing space after %d, causes numbers to be concatenated without spaces. Expected format includes a space after each popped value.
            }
        }
    }
    return 0;
}