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
    f(0,x-1); // @@ [The function call f(0, x-1) generates permutations correctly but does not ensure lexicographical order in the output because the algorithm uses a swapping-based backtracking approach that doesn't maintain sorted order across recursive calls. The problem requires output in lexicographical order, which this implementation fails to guarantee.]
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