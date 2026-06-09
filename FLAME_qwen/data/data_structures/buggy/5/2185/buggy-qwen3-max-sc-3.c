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
    while(scanf("%d%d",&c[j],&d[j])!=EOF) // @@ [This loop condition causes undefined behavior because it doesn't check for newline termination as required by the input format. It will keep reading until EOF, which may not occur during normal interactive input or when input ends with a newline, leading to incorrect parsing of the second polynomial.]
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
                e[i]=e[i]+e[j]; // @@ [This line incorrectly accumulates coefficients multiple times during nested loops, leading to overcounting. When two terms have the same exponent, their coefficients are added repeatedly in both directions (i,j) and (j,i), causing wrong results.]
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
            if(g[i]==m&&(e[i]!=0||f[i]!=0)) // @@ [The condition `e[i]!=0||f[i]!=0` is flawed: if a term has coefficient 0 but non-zero exponent (which shouldn't be printed), it would still be printed. Also, zero-degree terms with zero coefficient might be mishandled. Moreover, the ranking logic using array `g` does not correctly sort exponents in descending order due to incorrect ranking computation.]
            {
                printf("%d %d ",e[i],f[i]);
                m--;
                i=0; // @@ [Resetting loop variable `i` inside the loop leads to undefined behavior and potential infinite loops or skipped elements, as it interferes with the for-loop's control flow.]
            }
        }
    }
    return 0;
}