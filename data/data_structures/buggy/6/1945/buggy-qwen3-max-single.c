#include<stdio.h>
int a[100]={0};
int main()
{
    int x,i=0;
    scanf("%d",&x);
    while(x!=-1)
    {
        if(x==1)
        {
            scanf("%d",&x);
            if(i==99)
            {
                printf("error ");
            }
            else
            {
                a[i]=x;
                i++;
            }
        }
        else
        {
            if(i==0)
            {
                printf("error ");
            }
            else
            {
                printf("%d ",a[i-1]); // @@ [The original code does not print the popped element; it just sets a[i]=0 and decrements i. The problem requires outputting the popped value, which should be a[i-1] before decrementing.]
                i--;
            }
        }
        scanf("%d",&x);
    }
    return 0;
}