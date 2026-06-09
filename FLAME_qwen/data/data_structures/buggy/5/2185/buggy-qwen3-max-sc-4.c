#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int a[100005],b[100005],c[100005],d[100005],e[100005],f[100005],g[105];
int main()
{
    int n,i=0,j=1,m=0,k,h;
    char p;
    scanf("%d%d",&a[0],&b[0]);
    p=getchar();
    while(p!='\n')
    {
        i++;
        scanf("%d%d",&a[i],&b[i]);
        p=getchar();
    }
    n=i;
    scanf("%d%d",&c[0],&d[0]);
    while(scanf("%d%d",&c[j],&d[j])!=EOF) // @@ [This loop condition causes undefined behavior because it doesn't check for newline termination properly and may read beyond intended input, leading to incorrect parsing of the second polynomial. Also, EOF is not guaranteed to be encountered in normal input scenarios with newline-terminated lines.]
    {
        j++;
    }
    k=j-1;
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=k;j++)
        {
            e[m]=a[i]*c[j];
            f[m]=b[i]+d[j];
            m++;
        }
    }
    h=m-1;
    n=0;
    k=0;
    for(i=0;i<=h;i++)
    {
        for(j=0;j<=h;j++)
        {
            if(f[i]>=f[j])
                n++;
            if(f[i]==f[j]&&i!=j)
            {
                e[i]=e[i]+e[j]; // @@ [This line incorrectly accumulates coefficients from already-zeroed terms or double-counts during combination, leading to wrong results. It also modifies e[j] and f[j] while still using them in later iterations.]
                e[j]=0;
                f[j]=0;
            }
        }
        g[i]=n;
        n=0;
    }
    for(m=h+1;m>=0;m--)
    {
        for(i=0;i<=h;i++)
        {
            if(g[i]==m&&(e[i]!=0||f[i]!=0)) // @@ [The condition (e[i]!=0||f[i]!=0) is flawed: if e[i] is 0 but f[i] is non-zero, it prints a zero-coefficient term, which violates the problem's requirement to omit zero-coefficient terms. Also, g[i] was computed as a rank-like count, not actual exponent values, so sorting by g[i] does not correctly order terms by exponent.]
            {
                printf("%d %d ",e[i],f[i]);
                m--;
                i=0; // @@ [Resetting loop variable i inside the loop causes unpredictable iteration behavior and potential infinite loops or skipped elements.]
            }
        }
    }
    return 0;
}