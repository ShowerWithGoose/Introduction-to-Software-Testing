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
        printf("%d", arr[i]); // @@ [Missing space between numbers as required by output format; also indexing starts at 1 but array may not be properly initialized at index 0]
    }
    printf("\n");
}
void perm( int arr[], int p, int q)
{
    if(p == q)
    {
        printArr(arr, q);
    }
    for(int i = p; i <= q; i++) // @@ [Missing braces around the loop body causes only the first statement (swap) to be inside the loop; the recursive call and swapback will execute unconditionally after the loop]
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
        p[i] = i; // @@ [Array indexing starts at 1, leaving p[0] unused; but functions expect valid data starting from index 1, which is inconsistent with typical C conventions and may cause off-by-one errors]
    }
    perm(p, 1, a); // @@ [Passing 1 as starting index instead of 0 leads to skipping p[0] and using p[1..a], but array size is only 10 and for N=10 this accesses p[10] which is out of bounds (valid indices: 0-9)]
}