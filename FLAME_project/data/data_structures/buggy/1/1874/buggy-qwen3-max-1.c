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
    for(l=0;l<n;l++)
    {
        a[l]=l+1; // @@ This line resets the entire array to initial state (1,2,...,n) on every swap, destroying any prior permutation state and preventing correct backtracking.
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
            exchange(a,p,k); // @@ Because exchange() resets the array before swapping, this "restore" step does not actually restore the original state—it again resets and swaps, leading to incorrect permutations and duplicates.
        }
    }
}