#include <stdio.h>
#include <string.h>
#include <math.h>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#include <stdlib.h>
int n, a[11], b[11][11];
void pr(int*x) {
    for (int i = 1; i <= n; i++) {
        printf("%d", x[i]); //TODO @@ [Missing space after each number as required by output format; should be "%d "]
    }
    puts("");
}
void copy(int*x, int*y) {//y¸øx
    for (int i = 1; i <= n; i++) {
        x[i] = y[i]; //TODO
    }
}
void swap(int*b, int x, int i) {
    int t;
    t = *(b + n - x + 1);
    *(b + n - x + 1) = *(b + n - x + 1 + i);
    *(b + n - x + 1 + i) = t; @@ [Incorrect pointer arithmetic: indexing logic is flawed and does not correctly swap elements in the intended permutation array; also, 'b' here shadows global 'b', causing confusion and likely wrong behavior]
}
void f(int x) {
    if (x == 1) {
        pr(a);
        return;//TODO
    }
    copy(b[x],a);
    f(x - 1);
    for (int i = 1; i < x; i++) {
        swap(a, x, i); @@ [Passing 'a' (int*) to parameter expecting 'int*', but inside swap uses incorrect offset based on 'n - x + 1', which may access out-of-bound or wrong indices]
        f(x - 1);
    }
    copy(a,b[x]);
    return;
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        a[i] = i; //TODO
    }
    f(n);
    return 0;
}