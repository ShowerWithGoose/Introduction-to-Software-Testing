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
        printf("%d", arr[i]); // @@ [Missing space between numbers as required by output format; should print "%d " instead of "%d"]
    }
    printf("\n");
}
void perm( int arr[], int p, int q)
{
    if(p == q)
    {
        printArr(arr, q);
    }
    for(int i = p; i <= q; i++) // @@ [Missing else block; after the base case, recursive case should only run if p != q, otherwise leads to redundant calls and incorrect behavior]
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
        p[i] = i; // @@ [Array indexing starts at 1, but standard C arrays are 0-indexed; this skips p[0] and may cause undefined behavior when a=10 since p[10] is out of bounds for p[10]]
    }
    perm(p, 1, a); // @@ [Passing starting index as 1 instead of 0 causes the first element (p[0]) to be ignored and may access out-of-bounds memory]
}