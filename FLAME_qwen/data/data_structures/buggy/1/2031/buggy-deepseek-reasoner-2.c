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
        printf("%d", arr[i]); // @@ Missing space after %d; should be "%d " to separate numbers.
    }
    printf("\n");
}
void perm( int arr[], int p, int q)
{
    if(p == q) // @@ Missing else clause or return after base case; the for loop below should not execute when p==q.
    {
        printArr(arr, q);
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
    int a, p[10] = {0}; // @@ Array size too small for N=10 when using 1-indexed; causes out-of-bounds access for p[10].
    scanf("%d", &a);
    for(int i = a; i > 0; i--)
    {
        p[i] = i;
    }
    perm(p, 1, a);
}