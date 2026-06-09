#include <stdio.h>

void arrangement(int, int, int*, int*);

int main()
{
    int maxn;
    int arr[15], used[15];
    scanf("%d", &maxn);
    arrangement(maxn, 0, arr, used);
    return 0;
}

void arrangement(int maxn, int idx, int* arr, int* used)
{
    int i;
    if (idx == 0) { // initialize the 'used' array
        for (i = 0; i < maxn; i++) {
            used[i] = 0;
        }
    }
    if (idx >= maxn) { // break the iteration
        for (i = 0; i < maxn - 1; i++) {
            printf("%d ", arr[i] + 1);
        }
        printf("%d\n", arr[i] + 1);
        return;
    }
    for (i = 0; i < maxn; i++) {
        if (!used[i])
        {
            used[i] = 1;
            arr[idx] = i;
            arrangement(maxn, idx + 1, arr, used);
            used[i] = 0;
        }
    }
}

