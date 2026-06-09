#include<stdio.h>
int n,a[20];
void exchange(int a[],int p,int q);
void rank(int a[],int p,int q);
int main()
{
    int i;
    scanf("%d",&n);
    for( i=0;i<n;i++)
    {
        a[i]=i+1;
    }
    rank(a,0,n-1);
    return 0;
} 
void exchange(int a[],int p,int q)
{
    int m,l;
    for(l=0;l<n;l++) // @@ This loop incorrectly resets the array to its initial state [1, 2, ..., n] before every swap, destroying the current permutation state and breaking the backtracking logic.
    {
        a[l]=l+1;
    }
    m=a[p];
    a[p]=a[q];
    a[q]=m;
}
void rank(int a[],int p,int q)
{
    if(p==q)
    {
        int j;
        for( j=0;j<n;j++)
        {
            printf("%d ",a[j]);
        }
        printf("\n");
        return ;
    }
    else
    {
        int k;
        for( k=p;k<=q;k++)
        {
            exchange(a,k,p);
            rank(a,p+1,q);
            exchange(a,p,k);
        }
    }
}