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
        printf("%d", arr[i]); // @@ [The output format requires space-separated integers and a space after each number except the last; also missing space separator]
    }
    printf("\n");
}
void perm( int arr[], int p, int q)
{
    if(p == q)
    {
        printArr(arr, q);
    }
    for(int i = p; i <= q; i++) // @@ [Missing braces around the body of the if statement above causes the loop to always execute even after base case, leading to incorrect recursion and potential out-of-bounds access]
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
        p[i] = i; // @@ [Array indexing starts at 1, but C arrays are 0-indexed; this leaves p[0] unused and may cause undefined behavior when a=10 since p has size 10 (indices 0-9), but p[10] would be accessed if a=10]
    }
    perm(p, 1, a); // @@ [Calling perm starting at index 1 skips p[0] and uses indices 1..a, which is inconsistent with standard 0-based array usage and may go out of bounds when a=10]
}