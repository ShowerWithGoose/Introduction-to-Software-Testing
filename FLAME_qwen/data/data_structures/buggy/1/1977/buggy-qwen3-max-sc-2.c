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
        arr[a] = arr[a + 1]; // @@ [This line incorrectly always modifies arr[a] instead of arr[i]; it should be arr[i] = arr[i + 1]; also, the loop logic fails to restore the original array state correctly after recursion]
    }
    arr[b] = temp;
}

void perm(int arr[], int start, int end)
{
    if (start == end)
    {
        for (int i = 0; i <= end; i++)
        {
            printf("%d ", arr[i]); // @@ [This prints arr[0] through arr[end], but when start==end, only indices 0 to end are valid; however, the bigger issue is that the loop condition should be i < end or i <= end consistently with array bounds. In this case, since end = num-1, i <= end is correct, so this line is actually okay. The real problem lies in superSwapBack.]
        }
        printf("\n");
    }
    else
    {
        for (int i = start; i <= end; i++)
        {
            superSwap(arr, start, i);
            perm(arr, start + 1, end);
            superSwapBack(arr, i, start); // @@ [The arguments are passed in reverse order: it should be superSwapBack(arr, start, i) to undo the effect of superSwap(arr, start, i). Passing (i, start) causes incorrect restoration.]
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