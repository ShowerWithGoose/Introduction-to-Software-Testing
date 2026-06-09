#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int hashtable[10000]={0},a[10000];
void func(int n,int d);
int n,n1,n2;

int main()
{
    scanf("%d",&n);
    n1=n,n2=n;
    func(n,1);
    return 0;
}

void func(int n,int d)
{
    int i;
    if(d==n+1)
    {
        for(i=1;i<=n;i++)
        {
            printf("%d ",a[i]);
        }
        putchar('\n');
        return;
    }
    for(i=1;i<=n;i++)
    {
        if(hashtable[i]==0)
        {
            a[d]=i;
            hashtable[i]=1;
            func(n,d+1);
            hashtable[i]=0;
        }
    }
}



