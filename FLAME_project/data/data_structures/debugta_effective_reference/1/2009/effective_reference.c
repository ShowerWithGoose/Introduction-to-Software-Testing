#include <stdio.h>

int N = 1;
int re[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

void print() {
    int i = 0;
    for (; i < N; i++) {
        printf("%d ", re[i]);
    }
    puts("");
}

void swap(int a, int b) {
    int used = re[a];
    re[a] = re[b];
    re[b] = used;
    return;
}

void solve(int n) {
    if (n == 2) {
        print();
        swap(N - 1, N - 2);
        print();
        swap(N - 1, N - 2);
        return;
    }
    solve(n - 1);
    int i = 1;
    for (; i < n; i++) {
        int j = i;
        for (; j > 0; j--) {
            swap(N - n + j, N - n + j - 1);
        }
        solve(n - 1);
        for (; j < i; j++) {
            swap(N - n + j, N - n + j + 1);
        }
    }
    return;
}

int main() {
    scanf("%d", &N);
    if (N == 1) {
        printf("1");
        return 0;
    }
    solve(N);
    return 0;
}


