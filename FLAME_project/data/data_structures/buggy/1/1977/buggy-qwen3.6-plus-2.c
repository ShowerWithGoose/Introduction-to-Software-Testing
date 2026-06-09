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
    int temp = arr[a]; // @@ The logic for restoring the array state is incorrect. It should rotate elements from a+1 to b left by one position, but this implementation overwrites arr[a] repeatedly without shifting the intermediate elements correctly, leading to data corruption.
    for (int i = a; i < b; ++i) // @@ This loop fails to properly shift elements arr[a+1]...arr[b] to the left. It should be arr[i] = arr[i+1].
    {
        arr[a] = arr[a + 1]; // @@ This line incorrectly assigns arr[a+1] to arr[a] in every iteration, losing original values and not performing the required left shift.
    }
    arr[b] = temp; // @@ Placing the saved temp at arr[b] is part of the rotation, but since the shift was broken, the final state is wrong.
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
            superSwapBack(arr, i, start); // @@ The arguments are swapped compared to superSwap (which takes a, b where a is destination index for the element at b). More importantly, the function itself is buggy.
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