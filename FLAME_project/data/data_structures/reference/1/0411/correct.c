#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define eps 1e-10

int main()
{
    int N=1,s,n,m,i,j,k,r,c[15];
    scanf("%d",&n);
    for(i=n;i>1;i--)
    {
        N=N*i;
    }
    for(i=0;i<N-1;i++)
    {
        r=N;
        for(m=i,k=1;k<n;k++)
        {
            r=r/(n-k+1);
            if(r==0)
                r=n-k+1;
            c[k]=m/r+k;
            s=n;
            while(1)
            {
                if(s>=c[k])
                {
                    for(j=1;j<k;j++)
                    {
                        if(c[j]==s)
                            c[k]=c[k]-1;
                    }
                }
                s--;
                if(s<c[k])
                    break;

            }
            printf("%d ",c[k]);
            m=m%r;

        }
        c[k]=m/r+k;
        s=n;
        while(1)
        {
            if(s>=c[k])
            {
                for(j=1;j<k;j++)
                {
                    if(c[j]==s)
                        c[k]=c[k]-1;
                }
            }
            s--;
            if(s<c[k])
                break;

        }
        printf("%d\n",c[k]);

    }

    for(1;n>1;n--)
    {
        printf("%d ",n);

    }
    printf("1");


    return 0;
}



