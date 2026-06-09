#include <stdio.h>
void superSwap(int arr[], int a, int b)
{
    int temp = arr[b];
    for (int i = b; i > a; --i)
    {
        arr[i] = arr[i - 1];
    }
    arr[a] = temp;
}

void superSwapBack(int arr[], int a, int b)
{
    int temp = arr[a];
    for (int i = a; i < b; ++i)
    {
        arr[a] = arr[a + 1]; // @@ Incorrect assignment inside loop; should be arr[i] = arr[i + 1]; to properly shift elements left.
    }
    arr[b] = temp;
}

void perm(int arr[], int start, int end)
{
    if (start == end)
    {
        for (int i = 0; i <= end; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
    else
    {
        for (int i = start; i <= end; i++)
        {
            superSwap(arr, start, i);
            perm(arr, start + 1, end);
            superSwapBack(arr, i, start); // @@ Arguments are swapped; should be superSwapBack(arr, start, i); to correctly reverse the rotation performed by superSwap.
        }
    }
}

int main()
{
    int num;
    scanf("%d", &num);
    int arr[num];
    for (int i = 0; i < num; ++i)
    {
        arr[i] = i + 1;
    }
    perm(arr, 0, num - 1);
    return 0;
}