#include<stdio.h>

void exchange(int a[], int i, int j) // @@ [This simple swap does not maintain lexicographic order; should use a rotation that moves the element from j to i and shifts other elements.]
{
    int temp=a[j];
    a[j]=a[i];
    a[i]=temp;
}

void PrintResult(int a[], int n)
{
    int i=0;
    for(i=0;i<n;i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void function(int a[], int i, int j)
{
    int k;
    if(i==j)
    {
        PrintResult(a, j+1);
    }else
    {
        for(k=i;k<=j;k++)
        {
            exchange(a, i, k); // @@ [This call does a simple swap; should use a rotation (like swap in reference) to preserve prefix order for lexicographic output.]
            function(a, i+1, j);
            exchange(a, i, k); // @@ [This call restores with a simple swap; should use a reverse rotation (like swapback in reference) to correctly revert the array.]
        }
    } 
}

int main()
{
    int a[20];
    int n;
    int i=0;
    scanf("%d", &n);
    for(i=0;i<n;i++)
    {
        a[i]=i+1;
    }
    function(a, 0, n-1);
    return 0;
}