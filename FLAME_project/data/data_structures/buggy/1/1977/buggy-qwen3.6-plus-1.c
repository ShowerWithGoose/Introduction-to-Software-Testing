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
        arr[a] = arr[a + 1]; // @@ [Logic Error: The index inside the loop should be 'i', not 'a'. It should be arr[i] = arr[i+1] to shift elements left. Using 'a' repeatedly overwrites arr[a] incorrectly and fails to restore the array state.]
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
            superSwapBack(arr, i, start); // @@ [Argument Order Error: The function superSwapBack expects (arr, a, b) where elements are shifted from a to b. Here 'i' is passed as 'a' and 'start' as 'b'. Since i >= start, the loop condition i < b (i < start) in superSwapBack will likely fail or behave unexpectedly if i > start. It should be superSwapBack(arr, start, i) to reverse the operation of superSwap(arr, start, i).]
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