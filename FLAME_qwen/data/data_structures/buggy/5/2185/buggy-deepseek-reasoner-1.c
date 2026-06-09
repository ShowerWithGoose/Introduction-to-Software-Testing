#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int a[100005],b[100005],c[100005],d[100005],e[100005],f[100005],g[105]; // @@ Array g size too small; max terms can exceed 105.
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
    while(scanf("%d%d",&c[j],&d[j])!=EOF) // @@ Does not terminate at end of second line; may read unintended input.
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
            if(f[i]>=f[j]) // @@ Counting does not correctly rank exponents; used with modified f values.
                n++;
            if(f[i]==f[j]&&i!=j) // @@ Combining inside same loop corrupts subsequent counting and order.
            {
                e[i]=e[i]+e[j];
                e[j]=0;
                f[j]=0;
            }
        }
        g[i]=n; // @@ Potential array index out of bounds if i >= 105.
        n=0;
    }
    for(m=h+1;m>=0;m--) // @@ Loop variable m reused and modified inside causing erratic behavior.
    {
        for(i=0;i<=h;i++)
        {
            if(g[i]==m&&(e[i]!=0||f[i]!=0)) // @@ Condition should be e[i]!=0; also sorting logic flawed.
            {
                printf("%d %d ",e[i],f[i]);
                m--; // @@ Modifying outer loop variable leads to incorrect iteration.
                i=0; // @@ Reset inside inner loop causes potential infinite loop.
            }
        }
    }
    return 0;
}