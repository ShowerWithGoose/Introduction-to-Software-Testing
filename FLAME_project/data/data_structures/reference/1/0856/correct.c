#include <stdio.h>
void Print(int a) {
    int i, arr[11];
    for (i = 1; i <= a; i++) arr[i] = i;
    while (arr[1] <= a) {
        if (judge(arr, a) == 1) {
            for (i = 1; i <= a; i++) printf("%d ", arr[i]);
            printf("\n");
        }
        arr[a]++;
        for (i = a; i > 1; i--)
            if (arr[i] > a) {
                arr[i - 1]++;
                arr[i] = 1;
            }
    }
    return;
}
int judge(int a[], int b) {
    int i, j;
    for (i = j = 1; i < b; j++) {
        if (a[i] == a[i + j]) return 0;
        if (i + j == b) {
            i++;
            j = 0;
        }
    }
    return 1;
}
int main() {
    int a;
    scanf("%d", &a);
    Print(a);
    return 0;
}


