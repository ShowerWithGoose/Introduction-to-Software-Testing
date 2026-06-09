#include <stdio.h>
#include <math.h>
#include <string.h>

void swap(int arr[], int p, int q)
{
    int temp = arr[q];
    for(int i = q; i >= p + 1; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[p] = temp;
}

void swapback(int arr[], int p, int q)
{
    int temp = arr[p];
    for(int i = p; i <= q - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    arr[q] = temp;
}

void printArr(int arr[], int n)
{
    for(int i = 1; i <= n; i++)
    {
        printf("%d ", arr[i]); // @@ Missing space separator between integers as required by the output format.
    }
    printf("\n");
}
void perm( int arr[], int p, int q)
{
    if(p == q)
    {
        printArr(arr, q); return; // @@ Missing return statement after the base case, which causes unnecessary recursive calls and incorrect permutation generation.
    }
    for(int i = p; i <= q; i++)
    {
        swap(arr, p, i);
        perm(arr, p + 1, q);
        swapback(arr, p, i);
    }
}

int main()
{
    int a, p[11] = {0}; // @@ Array size is too small for N=10, causing out-of-bounds access when p[10] is assigned. Increased to 11.
    scanf("%d", &a);
    for(int i = a; i > 0; i--)
    {
        p[i] = i;
    }
    perm(p, 1, a);
}