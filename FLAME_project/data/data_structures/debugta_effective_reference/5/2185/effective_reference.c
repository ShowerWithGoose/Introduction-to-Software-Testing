#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    int a[100]={0},b[100]={0},c[100]={0},d[100]={0},e[100]={0},f[100]={0};
    int n=0,k=0,m=0,temp,h;
    char op=' ';
    while(op!='\n')
    {
        scanf("%d%d%c",&a[n],&b[n],&op);
        n++;
    }
    op=' ';
    while(op!='\n')
    {
        scanf("%d%d%c",&c[k],&d[k],&op);
        k++;
    }//读入没有任何问题
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<k;j++)
        {
            e[m]=a[i]*c[j];
            f[m]=b[i]+d[j];
            m++;
        }
    }
    for(int i=0;i<n*k;i++)
    {
        for(int j=0;j<n*k-i;j++)
        {
            if(f[j]>f[j+1])
            {
                temp=f[j+1];
                f[j+1]=f[j];
                f[j]=temp;
                temp=e[j+1];
                e[j+1]=e[j];
                e[j]=temp;
            }
        }
    }
    h=n*k;
    for(int i=0;i<=h;i++)
    {
        if(f[i]==f[i+1])
        {
            e[i]+=e[i+1];
            for(int p=i+1;p<=h;p++)
            {
                e[p]=e[p+1];
                f[p]=f[p+1];
            }
            h--;
            i--;
        }
    }
    for(int i=h;i>=0;i--)
    {
        if(e[i]!=0)
        printf("%d %d ",e[i],f[i]);
    }
    return 0;
}

