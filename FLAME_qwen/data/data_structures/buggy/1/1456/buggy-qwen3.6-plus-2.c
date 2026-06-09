#include<stdio.h>

void exchange(int a[], int i, int j) // @@ Simple swap operation does not maintain lexicographical order of permutations. A shift/rotation is required to preserve the relative order of remaining elements.
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
            exchange(a, i, k); // @@ Simple swap breaks lexicographical order. Should use a shift operation to move element k to position i while preserving relative order of others.
            function(a, i+1, j);
            exchange(a, i, k); // @@ Corresponding swap-back also needs to be a reverse shift to restore the array correctly for lexicographical generation.
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