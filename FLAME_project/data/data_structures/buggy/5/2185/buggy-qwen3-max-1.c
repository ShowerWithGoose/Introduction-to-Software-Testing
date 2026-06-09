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
    while(scanf("%d%d",&c[j],&d[j])!=EOF)
    {
        j++;
    } // @@ [This loop reads until EOF, but the problem states that the second polynomial ends with a newline, not EOF. This causes overreading if input has trailing whitespace or extra newlines, leading to incorrect term count.]
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
            } // @@ [This merging logic is flawed: it adds e[j] to e[i] even when j < i, and later when i == j' (original j), it may add again, causing double-counting. Also, setting e[j]=0/f[j]=0 doesn't remove the term properly and interferes with sorting/grouping.]
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
                m--;
                i=0; // @@ [Resetting loop variable i inside the loop causes unpredictable iteration behavior and may skip terms or cause infinite loops. Also, g[i] does not correctly represent rank/order for sorting by exponent.]
            }
        }
    }
    return 0;
}