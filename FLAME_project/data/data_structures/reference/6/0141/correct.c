#include<stdio.h>
int main()
{
    int a[100],n,i=1;
    scanf("%d",&n);
    while(n!=-1)
    {
        if(n==1)
        {
            if(i!=100)
            {
            scanf("%d",&a[i]);
            i++;
            }
            else
            {
                printf("error ");
            }
        }
        else
        {
            if(i!=1)
            {
                printf("%d ",a[i-1]);
                i--;
                a[i]='\0';
            }
            else
            {
                printf("error ");
            }
        }
        scanf("%d",&n);
    }
}



