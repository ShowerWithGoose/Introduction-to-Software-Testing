#include<stdio.h>

void exchange(int a[], int i, int j) // @@ Standard swap does not preserve lexicographical order; a shift operation is required to maintain the sorted sequence of remaining elements.
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
            exchange(a, i, k); // @@ Swapping disrupts the relative order of remaining elements, causing non-lexicographical output.
            function(a, i+1, j);
            exchange(a, i, k); // @@ Backtracking with swap fails to restore the original sorted order needed for lexicographical generation.
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