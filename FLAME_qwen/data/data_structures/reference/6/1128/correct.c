#include<stdio.h>
int main()
{
    int number,a[100],sum=0;
    while(1)
    {
        scanf("%d",&number);
        if(number==1)
        {
            scanf("%d",&a[sum]);
            sum++;
        }
        else if(number==0)
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
        else if(number==-1)
        break;
    }
}
