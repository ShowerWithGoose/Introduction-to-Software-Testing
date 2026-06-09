#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int a[100005],b[100005],c[100005],d[100005],e[100005],f[100005],g[105]; // @@ (line 6) potential error: g size 105 may be too small for large number of product terms, causing out-of-bounds access.
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
    while(scanf("%d%d",&c[j],&d[j])!=EOF)
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
            if(f[i]>=f[j]) // @@ (line 42) error: counting condition is reversed for descending order; should be f[i]<=f[j] to count larger exponents.
                n++;
            if(f[i]==f[j]&&i!=j) // @@ (line 44) error: combining terms inside the counting loop causes interference and incorrect g[i] values.
            {
                e[i]=e[i]+e[j];
                e[j]=0;
                f[j]=0;
            }
        }
        g[i]=n; // @@ (line 51) error: g[i] may be incorrect due to modifications and counting condition.
        n=0;
    }
    for(m=h+1;m>=0;m--) // @@ (line 54) error: outer loop variable m is modified inside (line 61), causing skipped ranks.
    {
        for(i=0;i<=h;i++)
        {
            if(g[i]==m&&(e[i]!=0||f[i]!=0)) // @@ (line 58) error: relies on flawed g[i] and order; does not correctly sort descending.
            {
                printf("%d %d ",e[i],f[i]);
                m--; // @@ (line 61) error: modifying loop variable m inside loop leads to incorrect iteration.
                i=0; // @@ (line 62) error: setting i=0 does not restart from 0 due to for loop increment; should be i=-1.
            }
        }
    }
    return 0;
}