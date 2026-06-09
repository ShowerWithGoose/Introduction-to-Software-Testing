#include <stdio.h>

void arrangement(int, int, int*, int*);

int main()
{
    int N;
    int arr[15], used[15];
    scanf("%d", &N);
    arrangement(N, 0, arr, used);
    return 0;
}

void arrangement(int N, int start, int* arr, int* used)
{
    int i;
    if (start == 0) { // initialize the 'used' array
        for (i = 0; i < N; i++) {
            used[i] = 0;
        }
    }
    if (start >= N) { // break the iteration
        for (i = 0; i < N - 1; i++) {
            printf("%d ", arr[i] + 1);
        }
        printf("%d\n", arr[i] + 1);
        return;
    }
    for (i = 0; i < N; i++) {
        if (!used[i])
        {
            used[i] = 1;
            arr[start] = i;
            arrangement(N, start + 1, arr, used);
            used[i] = 0;
        }
    }
}

