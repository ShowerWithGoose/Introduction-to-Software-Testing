#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int main()
{
    long long ori[210][2];
    long long p1[105][2];
    long long p2[105][2];
    long long pf1[1005][2];
    int i,j,k,n1,n2,n,nf,nc;
    long long hold0,hold1;
    i=0;
    j=0;
    k=0;
    while(scanf("%lld %lld",&ori[i][0],&ori[i][1])!=EOF)
    {
        if(ori[i][0]==-1&&ori[i][0]==-1)
        {
            break;
        }
        i++;
    }
    n=i;
    p1[0][0]=ori[0][0];
    p1[0][1]=ori[0][1];
    for(i=1;i<n;i++)
    {
        if(ori[i-1][1]-ori[i][1]>0)
        {
            p1[i][0]=ori[i][0];
            p1[i][1]=ori[i][1];
        }
        else
        {
            break;
        }
    }
    n1=i;
    for(;i<n;i++)
    {
        p2[j][0]=ori[i][0];
        p2[j][1]=ori[i][1];
        j++;
    }
    n2=j;
    nf=n1*n2;
    nc=nf;
    for(i=0;i<n1;i++)
    {
        for(j=0;j<n2;j++)
        {
            pf1[k][0]=p1[i][0]*p2[j][0];
            pf1[k][1]=p1[i][1]+p2[j][1];
            k++;
        }
    }
    for(i=0; i<nf-1; i++)
    {
        for(j=0; j<nf-1-i; j++)
        {
            if(pf1[j][1]<pf1[j+1][1])
            {
                hold0 = pf1[j][0];
                hold1 = pf1[j][1];
                pf1[j][0] = pf1[j+1][0];
                pf1[j][1] = pf1[j+1][1];
                pf1[j+1][0] = hold0;
                pf1[j+1][1] = hold1;
            }
            else if(pf1[j][1]==pf1[j+1][1])
            {
                pf1[j][0]+=pf1[j+1][0];
                pf1[j+1][0]=-1;
                pf1[j+1][1]=-1;
                nc--;
            }
        }
    }
    for(i=0; i<nf-1; i++)
    {
        for(j=0; j<nf-1-i; j++)
        {
            if(pf1[j][1]<pf1[j+1][1])
            {
                hold0 = pf1[j][0];
                hold1 = pf1[j][1];
                pf1[j][0] = pf1[j+1][0];
                pf1[j][1] = pf1[j+1][1];
                pf1[j+1][0] = hold0;
                pf1[j+1][1] = hold1;
            }
        }
    }
    for(i=0;i<nc;i++)
    {
        printf("%lld %lld ",pf1[i][0],pf1[i][1]);
    }
    return 0;
}

