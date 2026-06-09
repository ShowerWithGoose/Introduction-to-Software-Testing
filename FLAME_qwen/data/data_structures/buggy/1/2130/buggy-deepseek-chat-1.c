#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#define eps 1e-15
void swap(int num[],int p,int q)
{
    int temp;
    temp=num[q];
    for(int i=q;i>=p;i--)
    {
        num[i]=num[i-1]; // @@ [Error: When i equals p, num[i-1] accesses num[p-1], which is out of bounds. The loop should stop at i > p to avoid accessing index p-1. Also, the original element at position p is overwritten before being saved.]
    } 
    num[p]=temp;
}
void reswap(int num[],int p,int q)
{
    int temp;
    temp=num[p];
    for(int i=p;i<=p;i++) // @@ [Error: The loop condition i<=p means it runs only once (i=p), so it only copies num[p] to num[p] (no shift). It should be i<q to shift elements left from p to q-1.]
    {
        num[i]=num[i+1];
    } 
    num[q]=temp;
}
void h(int num[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",num[i]);
    }
    printf("\n");
}
void f(int num[],int p,int q)
{
    if(p==q)
    {
        h(num,q+1);
    }
    else
    {
        for(int i=p;i<=q;i++)
        {
            swap(num,p,i);
            f(num,p+1,q);
            reswap(num,p,i);
        }
    }
}
int main()
{
    int num[10]={1,2,3,4,5,6,7,8,9,10};
    int m;
    scanf("%d",&m);
    f(num,0,m-1);
    return 0;
}