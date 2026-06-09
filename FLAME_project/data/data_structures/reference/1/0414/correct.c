#include <stdio.h>
int top;
int n;
int condition[10];
int ans[10];

int main()
{
    scanf("%d",&n);
    int i;
    for(i=0;i<n;i++)
        condition[i]=1;
    top=0;
    run(0);

    return 0;
}

void run(int depth)
{
    int i;
    if(depth==n)
    {
        for(i=0;i<n-1;i++)
            printf("%d ",ans[i]+1);
        printf("%d\n",ans[i]+1);
    }

    for(i=0;i<n;i++)
    {
        if(condition[i])
        {
            ans[top]=i;
            top++;
            condition[i]=0;
            run(depth+1);
            top--;
            condition[i]=1;
        }
    }


}
