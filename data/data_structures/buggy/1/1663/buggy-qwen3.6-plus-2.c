#include<stdio.h>

int n;
int a[101];
int b[101];

void qpl(int step)
{
    int i;
    if(step==n+1)
    {
        for(i=1;i<=n;++i)
        {
            printf("%d ",a[i]); // @@ Missing space separator between integers in the output, which violates the output format requirement.
        }
        printf("\n");
        return;
    }
    for(i=1;i<=n;++i)
    {
        if(b[i]==0)
        {
            a[step]=i;
            b[i]=1;
            qpl(step+1);
            b[i]=0;
        }
    }
}
int main()
{
    scanf("%d",&n);
    qpl(1);
    return 0;
}