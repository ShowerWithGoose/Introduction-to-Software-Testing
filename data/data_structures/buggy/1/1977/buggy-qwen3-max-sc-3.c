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
        arr[a] = arr[a + 1]; // @@ [This line incorrectly always modifies arr[a] instead of arr[i]; it should be arr[i] = arr[i + 1]; otherwise, it overwrites the same position repeatedly and fails to shift elements back correctly.]
    }
    arr[b] = temp;
}

void perm(int arr[], int start, int end)
{
    if (start == end)
    {
        for (int i = 0; i <= end; i++)
        {
            printf("%d ", arr[i]); // @@ [This loop prints arr[0] through arr[end], but when start==end, only indices 0 to num-1 are valid. However, more critically, in the base case, it should print exactly 'num' elements. The real issue is that the loop condition should be i < end or i <= end depending on indexing. Here, since end = num-1, i <= end is correct. So this line is actually OK. But note: the main bug is in superSwapBack.]
        }
        printf("\n");
    }
    else
    {
        for (int i = start; i <= end; i++)
        {
            superSwap(arr, start, i);
            perm(arr, start + 1, end);
            superSwapBack(arr, i, start); // @@ [The arguments are passed in wrong order: it should be superSwapBack(arr, start, i) to reverse the effect of superSwap(arr, start, i). Passing (i, start) when i >= start leads to incorrect behavior in superSwapBack, especially because the function expects a <= b, but here a=i, b=start and i>=start, so a>=b, which breaks the loop condition i < b in superSwapBack.]
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