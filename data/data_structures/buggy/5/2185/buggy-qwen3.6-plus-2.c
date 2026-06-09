#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int a[100005],b[100005],c[100005],d[100005],e[100005],f[100005],g[105]; // @@ Array g is too small (size 105) to store ranks for all terms after multiplication, which can easily exceed 105, causing out-of-bounds access.
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
            if(f[i]>=f[j])
                n++;
            if(f[i]==f[j]&&i!=j) // @@ Modifying f[j] and e[j] to 0 during iteration corrupts data for subsequent comparisons, leading to incorrect ranking and combination of like terms.
            {
                e[i]=e[i]+e[j];
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
            if(g[i]==m&&(e[i]!=0||f[i]!=0))
            {
                printf("%d %d ",e[i],f[i]);
                m--; // @@ Modifying the outer loop control variable m inside the inner loop disrupts the iteration order and can cause terms to be skipped or printed incorrectly.
                i=0;
            }
        }
    }
    return 0;
}