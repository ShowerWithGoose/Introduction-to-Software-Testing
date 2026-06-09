#include<stdio.h>

void exchange(int a[], int i, int j)
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
        printf("%d ", a[i]); // @@ [Prints trailing space after last number; expected no trailing space per reference program]
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
            exchange(a, i, k);
            function(a, i+1, j); // @@ [Recursive permutation algorithm does not guarantee lexicographic order; should use iterative next permutation to match expected sorted output]
            exchange(a, i, k);
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