#include<stdio.h>
#include<math.h>
void f(int a[],int b[],int n,int dep);
int main()
{
    int a[100]={0};
    int b[100]={0};
    int n;
    scanf("%d",&n);
    f(a,b,n,1);
    return 0;
}
void f(int a[],int b[],int n,int dep)
{
    int i;
    if(dep==n+1)
    {
        for(i=1;i<=n;i++)
        printf("%d",a[i]); // @@ Missing space between numbers; should be "%d " to match expected output format with spaces.
        printf("\n");
        return;
    }
    for(i=1;i<=n;i++)
    {
        if(b[i]==0)  
        {
            b[i]=1;
            a[dep]=i;
            f(a,b,n,dep+1);
            b[i]=0;
        }
    }
}