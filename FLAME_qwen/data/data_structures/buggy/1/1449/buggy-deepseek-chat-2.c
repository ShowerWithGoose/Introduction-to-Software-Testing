#include<stdio.h>

int a,b,m,n,x,p[1005],t;

void huan(int a,int b);
void pai(int m,int n);

int main()
{
    int j;
    scanf("%d",&x);
    for(j=1;j<=x;j++)
    {
        p[j]=j;
    }
    
    pai(1,x);
    
    return 0;
}

void pai(int m,int n)
{
    int k,i;
    if(m==n)
    {
        for(k=1;k<=x;k++)
        {
            printf("%d ",p[k]);
        }
        printf("\n");
    }
    else
    {
        for(i=m;i<=n;i++)
        {
            huan(m,i);
            pai(m+1,n);
            huan(m,i);
        }    
    }
}

void huan(int a,int b)
{
    t=p[a];
    p[a]=p[b];
    p[b]=t;
}