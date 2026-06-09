#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int N;
int i, j;
int px[11];
int ans[10];

int factorial() {
    px[0] = 1;
    int i;
    for (i = 1; i < 10; i++) {
        px[i] = i * px[i - 1];
    }
}

void print() {
    int i = 0;
    for (i = 0; i < N - 1; i++)
        printf("%d ", ans[i]);
    printf("%d\n", ans[i]);
}

void find() {
    for (i = N - 2; i >= 0; i--) {
        if (ans[i] < ans[i + 1])
            break;
    }
    int k1 = i;
    int tl = i + 1;
    for (i = k1 + 1; i < N; i++) {
        if (ans[i] > ans[k1] && ans[i] < ans[tl])
            tl = i;
    }
    int t;
    t = ans[k1];
    ans[k1] = ans[tl];
    ans[tl] = t;
    for (j = k1 + 1, i = N - 1; i > j; i--, j++) {
        t = ans[i];
        ans[i] = ans[j];
        ans[j] = t;
    }
}

int main() {
    factorial();
    scanf("%d", &N);
    int i;
    for (i = 0; i < N; i++) {
        ans[i] = i + 1;
    }
    print();
    for (i = 1; i < px[N]; i++) {
        find();
        print();
    }
}

