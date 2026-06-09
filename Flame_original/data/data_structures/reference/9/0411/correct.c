
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define eps 1e-10


int main()
{

    int n,a[5][105],i,j,k,s,d,p,q,l,f;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d%d%d%d",&a[1][i],&a[2][i],&a[3][i],&a[4][i]);
    }
    for(i=1;i<n;i++)
    {
        k=a[1][i];
        f=i;
        for(j=i+1;j<=n;j++)
        {
            if(k>a[1][j])
            {
                f=j;
                k=a[1][j];
            }
        }

        s=a[1][f];
        p=a[2][f];
        q=a[3][f];
        l=a[4][f];
        a[1][f]=a[1][i];
        a[2][f]=a[2][i];
        a[3][f]=a[3][i];
        a[4][f]=a[4][i];
        a[1][i]=s;
        a[2][i]=p;
        a[3][i]=q;
        a[4][i]=l;
    }

    for(i=1,l=1;i<n;i++)
    {
        s=a[3][i];
        d=a[4][i];
        for(j=i+1,k=1;j<=n;j++)
        {
            if(a[1][j]==s&&a[2][j]==d)
            {
                k++;
                s=a[3][j];
                d=a[4][j];
            }
        }
        if(k>l)
        {
            l=k;
            p=a[1][i];
            q=a[2][i];
        }
    }

    printf("%d %d %d",l,p,q);
    return 0;
}


