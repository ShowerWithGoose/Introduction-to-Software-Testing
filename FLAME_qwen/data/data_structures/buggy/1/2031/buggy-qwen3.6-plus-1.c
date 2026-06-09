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
        printf("%d", arr[i]); // @@ Missing space separator between integers. The output format requires each integer to be separated by a space.
    }
    printf("\n");
}
void perm( int arr[], int p, int q)
{
    if(p == q)
    {
        printArr(arr, q);
    }
    for(int i = p; i <= q; i++) // @@ Missing 'else' or 'return' after the base case. Without it, the loop executes unnecessarily when p == q, causing redundant recursive calls and potential logical errors.
    {
        swap(arr, p, i);
        perm(arr, p + 1, q);
        swapback(arr, p, i);
    }
}

int main()
{
    int a, p[10] = {0}; // @@ Array size is too small for 1-based indexing when N=10. Accessing p[10] causes out-of-bounds memory access. Should be p[11].
    scanf("%d", &a);
    for(int i = a; i > 0; i--)
    {
        p[i] = i;
    }
    perm(p, 1, a);
}