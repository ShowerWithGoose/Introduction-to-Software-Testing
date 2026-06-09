#include<stdio.h>

int main()
{
    int op,num,stk[100],chk = 0;
    scanf("%d",&op);
    while(op != -1)
    {
        if(op == 0)
        {
            if(chk == 0) printf("error ");
            else
            {
                printf("%d ",stk[chk]);
                chk --;
            }
        }
        else
        {
            scanf("%d",&num);
            if(chk == 99) printf("error ");
            else
            {
                chk++;
                stk[chk] = num;
            }
        }
        scanf("%d",&op);
    }
    return 0;
}

