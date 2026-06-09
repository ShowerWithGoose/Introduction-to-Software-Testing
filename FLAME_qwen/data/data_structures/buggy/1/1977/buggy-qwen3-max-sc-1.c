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
        arr[a] = arr[a + 1]; // @@ [This line incorrectly modifies arr[a] repeatedly instead of shifting elements forward; it should use arr[i] = arr[i + 1] to shift left]
    }
    arr[b] = temp;
}

void perm(int arr[], int start, int end)
{
    if (start == end)
    {
        for (int i = 0; i <= end; i++)
        {
            printf("%d ", arr[i]); // @@ [Loop condition should be i < end or i <= end-1 because array indices go from 0 to end (inclusive), but when start==end, we only want to print elements 0 to end, which is correct. However, note that in main, end = num-1, so this prints 0..num-1 which is correct. So actually this line is OK. But wait: the loop runs i=0 to i<=end, and end=num-1, so it prints num elements: indices 0 to num-1. That's correct. So no error here.]
        }
        printf("\n");
    }
    else
    {
        for (int i = start; i <= end; i++)
        {
            superSwap(arr, start, i);
            perm(arr, start + 1, end);
            superSwapBack(arr, i, start); // @@ [Arguments passed in wrong order: should be (arr, start, i) to reverse the effect of superSwap(arr, start, i). Current call superSwapBack(arr, i, start) treats 'i' as 'a' and 'start' as 'b', but since i >= start, this leads to incorrect behavior in superSwapBack]
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