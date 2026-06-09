#include<stdio.h>
#include<string.h>
int s[10];
void f(int ,int );
void huan1(int ,int );
void huan2(int,int);
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
        for(int i=0;i<=x;i++)
        printf("%d ",s[i]);
        printf("\n");
    }
    else
    {
        for(int i=n;i<=x;i++)
        {
            huan1(i,n);
            f(n+1,x);
            huan2(n,i);
        }
    }
}
void huan1(int x,int y)
{
    for(int i=x;i>y;i--)
    {
        int cmp=s[i];
        s[i]=s[i-1];
        s[i-1]=cmp;
    }
}
void huan2(int n,int i)
{
    for(int j=n;j<i;j++)
    {
        int cmp=s[j];
        s[j]=s[j+1];
        s[j+1]=cmp;
    }
}
