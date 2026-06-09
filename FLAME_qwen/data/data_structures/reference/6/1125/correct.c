#include<stdio.h>
int stack[110];
int main()
{
    int op;
    int num=0;
    while(scanf("%d",&op))
    {
        if(op==-1)
        {
            break;
        }
        else if(op==1)
        {
            continue;
        }
        else if(op==0)
        {
            if(num==0)
            {
                printf("error ");
            }
            else
            {
                printf("%d ",stack[num--]);
            }
        }
        else
        {
            if(num==100)
            {
                printf("error ");
            }
            else
            {
                stack[++num]=op;
            }
        }
    }
    return 0;
}
