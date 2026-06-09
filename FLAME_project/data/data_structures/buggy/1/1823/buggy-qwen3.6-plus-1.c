#include<stdio.h>
#include<string.h>
int s[10];
void f(int ,int );
void huan(int ,int );
int main()
{
    int x;
    scanf("%d",&x);
    for(int j=1;j<=x;j++)
    s[j-1]=j;
    f(0,x-1);
}
void f(int n,int x)
{
    if(n==x)
    {
        for(int i=0;i<=x;i++) // @@ The loop condition i<=x causes an out-of-bounds access and prints an extra element (s[x] which is 0 or garbage) instead of stopping at i<x. For N=2, x=1, it prints s[0], s[1], and s[2]. It should be i<x or i<=x-1. Also, logically, when n==x, we have fixed all positions from 0 to x-1. The array size is x. So indices are 0 to x-1. The loop should run from 0 to x-1.
        printf("%d ",s[i]);
        printf("\n");
    }
    else
    {
        for(int i=n;i<=x;i++)
        {
            huan(i,n);
            f(n+1,x);
            huan(i,n);
        }
    }
}
void huan(int x,int y)
{
    int cmp=s[x];
    s[x]=s[y];
    s[y]=cmp;
}