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
        arr[a] = arr[a + 1]; // @@ [This line incorrectly always modifies arr[a] instead of arr[i]; it should be arr[i] = arr[i + 1]; also, the loop logic is flawed for reversing the superSwap operation]
    }
    arr[b] = temp;
}

void perm(int arr[], int start, int end)
{
    if (start == end)
    {
        for (int i = 0; i <= end; i++) // @@ [This loop prints arr[0] to arr[end], but when start==end, only indices 0 to end are valid; however, in recursive calls, the array is modified in-place and this printing is correct in range. The real issue is elsewhere. However, note that the problem expects permutations of 1..N printed with space separation and newline, which this does. So this line is actually okay.]
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
            superSwapBack(arr, i, start); // @@ [The arguments passed are (i, start), but superSwapBack expects (a, b) where a < b to shift forward. Here, after superSwap(start, i), to undo it, we need to shift element at 'start' back to position 'i', but the current superSwapBack implementation is broken and also called with reversed argument order compared to what the function logic assumes]
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