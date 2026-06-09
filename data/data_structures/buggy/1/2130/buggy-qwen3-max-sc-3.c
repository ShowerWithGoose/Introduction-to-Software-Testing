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
    for(int i=p;i<=p;i++) // @@ [The loop condition 'i<=p' causes the loop to run only once, and when i==p, accessing num[i+1] (i.e., num[p+1]) may be incorrect. More critically, this loop does not properly reverse the effect of 'swap'. It should iterate from p to q-1 to shift elements left, but currently it only runs one iteration regardless of q. This leads to incorrect array state during backtracking, causing wrong permutations or undefined behavior.]
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