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
    while(scanf("%d%d",&c[j],&d[j])!=EOF) // @@ scanf skips whitespace including newlines, so it will not stop at the newline separating the two polynomials, causing it to read incorrectly or hang.
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
            if(f[i]==f[j]&&i!=j) // @@ Modifying f[j] to 0 during the ranking loop corrupts the exponent values used for sorting and combining, leading to incorrect rank calculation and lost terms.
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
                m--; // @@ Modifying the outer loop control variable m inside the inner loop causes incorrect iteration steps, skipping ranks and potentially causing infinite loops or missing output.
                i=0;
            }
        }
    }
    return 0;
}