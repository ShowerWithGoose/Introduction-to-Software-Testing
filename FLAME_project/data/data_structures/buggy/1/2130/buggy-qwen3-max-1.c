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
        num[i]=num[i-1];
    } 
    num[p]=temp;
}
void reswap(int num[],int p,int q)
{
    int temp;
    temp=num[p];
    for(int i=p;i<=p;i++) // @@ [The loop runs only once (i=p to i=p), but it should shift elements from p to q-1 leftward to restore the original array. The loop condition should be i < q, not i <= p.]
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