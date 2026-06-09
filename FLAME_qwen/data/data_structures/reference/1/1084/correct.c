#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define ll long long
#define ull unsigned long long

void turn(int *l,int k,int i)
{
    int tmp,j;
    tmp=l[i];
    for ( j = i; j > k; j--)
    {
        l[j]=l[j-1];
    }
    l[k]=tmp;
}

void rturn(int *l,int k,int i)
{
    int tmp,j;
    tmp=l[k];
    for ( j = k; j < i; j++)
    {
        l[j]=l[j+1];
    }
    l[i]=tmp;
}

void f(int *l,int k,int n)
{
    int i;
    if(k>n-1)
    {
        for ( i = 0; i < n; i++)
        {
            printf("%d ",l[i]);
        }
        printf("\n");
    }
    else
    {
        for ( i = k; i < n; i++)
        {
            turn(l,k,i);
            f(l,k+1,n);
            rturn(l,k,i);
        }
    }
}

int main()
{
    int i,n,l[12];
    scanf("%d",&n);
    for ( i = 0; i < n; i++)
    {
        l[i]=i+1;
    }
    f(l,0,n);
    return 0;
}
