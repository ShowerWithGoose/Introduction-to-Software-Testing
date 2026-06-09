#include "stdio.h"
#include "stdlib.h"

int input(int *op)
{
    scanf("%d",op);
    return *op;
}
int main()
{
    int op,cnt=0;
    int num[100];
    int Head=0;
    while(input(&op)!=-1)
    {
        if(op==1)
        {
            int x;
            scanf("%d",&x);
            if(cnt>=100)
                printf("error ");
            else
            {
                num[Head++]=x;
                cnt++;
            }
        }
        else
        {
            if(cnt<=0)
                printf("error ");
            else
            {
                printf("%d ",num[--Head]);
                cnt--;
            }
        }
    }
    return 0;
}

