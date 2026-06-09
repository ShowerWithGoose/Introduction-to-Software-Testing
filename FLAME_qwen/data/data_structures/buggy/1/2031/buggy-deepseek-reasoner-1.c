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
    for(int i = 1; i <= n; i++) // @@ array index out of bounds when n = 10, and missing spaces in output format
    {
        printf("%d", arr[i]); // @@ missing space between numbers, expected format requires spaces
    }
    printf("\n");
}
void perm( int arr[], int p, int q)
{
    if(p == q)
    {
        printArr(arr, q);
    }
    for(int i = p; i <= q; i++) // @@ missing else before for loop; base case should not proceed to recursive swap loop
    {
        swap(arr, p, i);
        perm(arr, p + 1, q);
        swapback(arr, p, i);
    }
}

int main()
{
    int a, p[10] = {0}; // @@ array size insufficient; indices 1..10 require at least size 11
    scanf("%d", &a);
    for(int i = a; i > 0; i--)
    {
        p[i] = i; // @@ out-of-bounds write when a = 10, p[10] does not exist
    }
    perm(p, 1, a);
}