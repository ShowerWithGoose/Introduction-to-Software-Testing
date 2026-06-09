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
    while(scanf("%d%d",&c[j],&d[j])!=EOF) // @@ Incorrect end condition; should detect newline, not EOF; causes hang or reads beyond input.
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
            if(f[i]>=f[j]) // @@ Counting includes zeroed terms (after combination), leading to incorrect rank.
                n++;
            if(f[i]==f[j]&&i!=j) // @@ Combination only adds to e[i]; after zeroing, subsequent passes may not sum all like terms correctly.
            {
                e[i]=e[i]+e[j];
                e[j]=0;
                f[j]=0;
            }
        }
        g[i]=n; // @@ Assigning rank based on count that includes zeroed terms; resulting order is wrong.
        n=0;
    }
    for(m=h+1;m>=0;m--) // @@ Outer loop variable m is modified inside, causing undetermined behavior.
    {
        for(i=0;i<=h;i++)
        {
            if(g[i]==m&&(e[i]!=0||f[i]!=0))
            {
                printf("%d %d ",e[i],f[i]);
                m--; // @@ Modifying loop control variable m disrupts the iteration; also resetting i is incorrect.
                i=0;
            }
        }
    }
    return 0;
}