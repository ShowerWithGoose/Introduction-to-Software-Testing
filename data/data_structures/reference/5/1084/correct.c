#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define ll long long
#define ull unsigned long long

int f(const void *a,const void *b)
{

}

int main()
{
    int a[20][2],b[20][2],r1[400][2],r2[400][2],i=0,j=0,k,l,n=0,n1=1,flag,tem;
    char c='a';
    while (c!='\n')
    {
        scanf("%d%d",&a[i][0],&a[i][1]);
        i++;
        c=getchar();
    }
    c='a';
    while (c!='\n')
    {
        scanf("%d%d",&b[j][0],&b[j][1]);
        j++;
        c=getchar();
    }
    for ( k = 0; k < i; k++)
    {
        for ( l = 0; l < j; l++)
        {
            r1[n][0]=a[k][0]*b[l][0];
            r1[n][1]=a[k][1]+b[l][1];
            n++;
        }
    }
    r2[0][0]=r1[0][0];r2[0][1]=r1[0][1];
    for ( i = 1; i < n; i++)
    {
        flag=1;
        for ( j = 0; j < n1; j++)
        {
            if (r2[j][1]==r1[i][1])
            {
                r2[j][0]+=r1[i][0];
                flag=0;
            }
        }
        if (flag)
        {
            r2[n1][0]=r1[i][0];
            r2[n1][1]=r1[i][1];
            n1++;
        }
    }
    for ( i = 0; i < n1; i++)
    {
        for ( j = i+1; j < n1; j++)
        {
            if (r2[i][1]<r2[j][1])
            {
                tem=r2[i][1];
                r2[i][1]=r2[j][1];
                r2[j][1]=tem;
                tem=r2[i][0];
                r2[i][0]=r2[j][0];
                r2[j][0]=tem;
            }
        }
    }
    for ( i = 0; i < n1; i++)
    {
        printf("%d %d ",r2[i][0],r2[i][1]);
    }
    return 0;
}
