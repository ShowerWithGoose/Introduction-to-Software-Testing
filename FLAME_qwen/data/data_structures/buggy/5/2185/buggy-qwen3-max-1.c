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
    while(scanf("%d%d",&c[j],&d[j])!=EOF) // @@ [This loop does not correctly detect end-of-line; it reads until EOF, which may include extra unintended input or hang if input doesn't end with EOF. The problem specifies that each polynomial ends with a newline, so this should check for newline like the first polynomial.]
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
                e[i]=e[i]+e[j]; // @@ [This double loop for combining like terms is flawed: it modifies e[j] and f[j] during iteration, leading to incorrect accumulation (e.g., adding already-zeroed terms or double-counting). Also, setting f[j]=0 breaks exponent comparison logic later.]
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
            if(g[i]==m&&(e[i]!=0||f[i]!=0)) // @@ [The condition (e[i]!=0||f[i]!=0) is incorrect: terms with zero coefficient should be omitted regardless of exponent. Also, g[i] was intended to represent rank/order but is computed incorrectly due to flawed comparison logic above.]
            {
                printf("%d %d ",e[i],f[i]);
                m--;
                i=0; // @@ [Resetting loop variable i inside the loop causes unpredictable behavior and potential infinite loops or skipped terms.]
            }
        }
    }
    return 0;
}