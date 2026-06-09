#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
int a[10]={0};
void f(int n,int lf);
int main()
{
    int n;
    scanf("%d",&n);
    f(n,1);

}
void f(int n,int lf)
{
for(int i=1;i<=n;i++)
{
    if(lf==1)
    {
        for(int j=0;j<10;j++)
            a[j]=0;
    }
    int s=0;
    for(int j=0;j<lf-1;j++)
        if(i==a[j])
           {
            s=1;
            break;
            }
            if(s==0)
    {
    a[lf-1]=i;
    if(lf<n)
        f(n,lf+1);
    else
    {
        for(int j=0;j<n;j++)
            printf("%d ",a[j]);
        printf("\n");
    }
}
}
}

