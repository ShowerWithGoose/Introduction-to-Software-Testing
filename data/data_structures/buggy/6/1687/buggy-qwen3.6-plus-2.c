#include<stdio.h>
int main()
{
    int zhan[100];
    int top=0;
    int opr,shu;
    while(1)
    {
        scanf("%d",&opr);
        if(opr==1)
        {
            if(top<=99)
            {
                scanf("%d",&zhan[top++]);
            }
            else
            {
                printf("error ");
            }
        }
        else if(opr==0)
        {
            if(top>0)
            {
                printf("%d",zhan[--top]); // @@ Missing space after the printed number. The problem requires a space after each popped element, including the last one.
            }
            else
            {
                printf("error ");
            }
        }
        else
        {
            break;
        }
    }
    return 0;
}