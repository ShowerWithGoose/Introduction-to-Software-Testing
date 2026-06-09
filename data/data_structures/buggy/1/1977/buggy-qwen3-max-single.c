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
        arr[a] = arr[a + 1]; // @@ [This line incorrectly modifies arr[a] repeatedly instead of shifting elements forward; it should use arr[i] = arr[i + 1] to shift the segment left]
    }
    arr[b] = temp;
}

void perm(int arr[], int start, int end)
{
    if (start == end)
    {
        for (int i = 0; i <= end; i++)
        {
            printf("%d ", arr[i]); // @@ [This prints arr[0] through arr[end], but when start==end, only indices 0 to num-1 are valid; however, the real issue is that the loop condition should be i < end or i <= end depending on indexing. Here, since end = num-1, i <= end is correct, so this line is actually okay. The main bug is in superSwapBack.]
        }
        printf("\n");
    }
    else
    {
        for (int i = start; i <= end; i++)
        {
            superSwap(arr, start, i);
            perm(arr, start + 1, end);
            superSwapBack(arr, i, start); // @@ [The arguments passed are (i, start), but superSwapBack expects (a, b) where a < b to shift left. However, after superSwap, the element originally at i is now at start, and we want to restore by moving it back from start to i. But due to the bug in superSwapBack implementation, the restoration fails. Also, note that the call order may be logically reversed.]
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