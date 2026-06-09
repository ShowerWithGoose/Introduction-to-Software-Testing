#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    int a[100]={0},b[100]={0},c[100]={0},d[100]={0},e[100]={0},f[100]={0};
    int i=0,j=0,k=0,temp,count;
    char op=' ';
    while(op!='\n')
    {
        scanf("%d%d%c",&a[i],&b[i],&op);
        i++;
    }
    op=' ';
    while(op!='\n')
    {
        scanf("%d%d%c",&c[j],&d[j],&op);
        j++;
    }//读入没有任何问题
    for(int m=0;m<i;m++)
    {
        for(int n=0;n<j;n++)
        {
            e[k]=a[m]*c[n];
            f[k]=b[m]+d[n];
            k++;
        }
    }
    for(int m=0;m<i*j;m++)
    {
        for(int n=0;n<i*j-m;n++)
        {
            if(f[n]>f[n+1])
            {
                temp=f[n+1];
                f[n+1]=f[n];
                f[n]=temp;
                temp=e[n+1];
                e[n+1]=e[n];
                e[n]=temp;
            }
        }
    }
    count=i*j;
    for(int m=0;m<=count;m++)
    {
        if(f[m]==f[m+1])
        {
            e[m]+=e[m+1];
            for(int p=m+1;p<=count;p++)
            {
                e[p]=e[p+1];
                f[p]=f[p+1];
            }
            count--;
            m--;
        }
    }
    for(int m=count;m>=0;m--)
    {
        if(e[m]!=0)
        printf("%d %d ",e[m],f[m]);
    }
    return 0;
}

