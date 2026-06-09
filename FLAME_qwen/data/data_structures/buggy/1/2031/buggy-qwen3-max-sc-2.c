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
        printf("%d", arr[i]); // @@ [The output format requires space-separated integers, but this prints without spaces. Also, indexing starts at 1, which skips arr[0] and may access uninitialized memory when n=1.]
    }
    printf("\n");
}
void perm( int arr[], int p, int q)
{
    if(p == q)
    {
        printArr(arr, q);
    }
    for(int i = p; i <= q; i++) // @@ [Missing braces around the loop body cause incorrect control flow: the recursive call and swapback will execute even after base case returns, leading to extra/incorrect permutations.]
    {
        swap(arr, p, i);
        perm(arr, p + 1, q);
        swapback(arr, p, i);
    }
}

int main()
{
    int a, p[10] = {0};
    scanf("%d", &a);
    for(int i = a; i > 0; i--)
    {
        p[i] = i; // @@ [Array indexing starts at 1, leaving p[0] unused. This causes inconsistency with typical 0-based array handling and leads to off-by-one errors in permutation logic and printing.]
    }
    perm(p, 1, a); // @@ [Calling perm starting at index 1 instead of 0 skips the first element and mismatches with array initialization, causing undefined behavior or missing permutations.]
}