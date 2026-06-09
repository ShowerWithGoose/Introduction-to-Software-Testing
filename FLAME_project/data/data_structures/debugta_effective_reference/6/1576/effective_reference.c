#include<stdio.h>
int main()
{
    int caozuo,a[100],sum=0;
    while(1)
    {
        scanf("%d",&caozuo);
        if(caozuo==1)
        {
            scanf("%d",&a[sum]);
            sum++;
        }
        else if(caozuo==0)
        {
            if(sum>-1)
            {
                sum--;
            }
            if(sum==-1)
            {
                printf("error ");
                sum=0;
            }
            else
            printf("%d ",a[sum]);
        }
        else if(caozuo==-1)
        break;
    }
}
