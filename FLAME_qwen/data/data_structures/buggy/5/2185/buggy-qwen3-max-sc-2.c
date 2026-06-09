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
    while(scanf("%d%d",&c[j],&d[j])!=EOF) // @@ [This loop does not correctly detect end-of-line; it reads until EOF, which may cause incorrect parsing if input ends with newline instead of EOF. Also, j starts at 1 but c[0],d[0] already read, so this overwrites or skips terms.]
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
                e[i]=e[i]+e[j];
                e[j]=0;
                f[j]=0;
            }
        }
        g[i]=n;
        n=0;
    }
    for(m=h+1;m>=0;m--) // @@ [Loop condition m>=0 is incorrect because m starts at h+1 (which is beyond array bounds) and decrements; also, inner loop resets i=0 causing potential infinite loop or missed terms.]
    {
        for(i=0;i<=h;i++)
        {
            if(g[i]==m&&(e[i]!=0||f[i]!=0))
            {
                printf("%d %d ",e[i],f[i]);
                m--; // @@ [Modifying loop variable m inside the loop leads to undefined behavior and skipped iterations.]
                i=0; // @@ [Resetting i to 0 inside the loop causes reprocessing of earlier indices and potential infinite loop.]
            }
        }
    }
    return 0;
}