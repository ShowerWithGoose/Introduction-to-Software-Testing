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
        for(int i=0;i<=x;i++)
        printf("%d ",s[i]);
        printf("\n");
    }
    else
    {
        for(int i=n;i<=x;i++) // @@ This loop's swapping order does not generate permutations in lexicographical order; the reference algorithm uses an incremental duplicate‑checking approach that iterates numbers from 1 to N, ensuring sorted output.
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