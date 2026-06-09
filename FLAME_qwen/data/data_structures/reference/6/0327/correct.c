#include <stdio.h>
int top=-1,a[100];
int main()
{
    int t,n;
    while(scanf("%d",&t)!=EOF)
    {
        if(t==-1)
        break;
        if(t==0)
        {
            if(top!=-1)
            {
                printf("%d ",a[top]);
                top--;
            }
            else
            printf("error ");
        }
        if(t==1)
        {
            scanf("%d",&n);
            if((top+1)!=100)
            {
                top++;
                a[top]=n;
            }
            else
            printf("error ");
        }
    }
    return 0;
}
