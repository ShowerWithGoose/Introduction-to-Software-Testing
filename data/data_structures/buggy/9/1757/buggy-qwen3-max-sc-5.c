#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define max(a,b) ((a>b)?(a):(b))
#define min(a,b) ((a<b)?(a):(b))

typedef struct {
    int x1;
    int y1;
    int x2;
    int y2;
} line;
int count = 1; // @@ [Global variable 'count' is initialized once and reused across test cases; however, in the loop it's reset to 1 only after use. But more critically, if multiple test runs occur (not in this problem), it could cause issues. However, the real issue is that this global 'count' is unnecessary and error-prone. But the actual compilation error is not here.]

int main() {
    int n;//Ïß¶ÎÊý
    int i = 0, j = 0;
    int count_max = 1, x, y; // @@ [Variables 'x' and 'y' are used uninitialized if no segment chain is found (i.e., if count never exceeds 1). According to constraints, there's always one max chain, but if n=0 or all chains length=1, 'x' and 'y' remain uninitialized, leading to undefined behavior — though not a compilation error.]
    int x2, y2;
    line a[10]; // @@ [Array size is fixed to 10, but problem doesn't specify maximum n. Reference program uses 150. If input n > 10, buffer overflow occurs. However, this is a runtime error, not compilation.]
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d%d%d%d", &a[i].x1, &a[i].y1, &a[i].x2, &a[i].y2);
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (a[i].x1 > a[j].x1) {
                line temp;
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;

            }
        }
    }
    for (i = 0; i < n; i++) {
        x2 = a[i].x2;
        y2 = a[i].y2;
        for (j = i + 1; j < n; j++) {
            if (a[j].x1 == x2 && a[j].y1 == y2) {
                count++;
                x2 = a[j].x2;
                y2 = a[j].y2;
            }
        }
        if (count > count_max) {
            count_max = count;
            x = a[i].x1;
            y = a[i].y1;
        }
        count = 1;
    }
    printf("%d %d %d", count_max, x, y); // @@ [If n == 0, this prints uninitialized x,y and count_max=1, which is invalid. Also, the problem states there is at least one segment? Not specified, but constraints imply n>=1. Still, not a compilation error.]

    return 0;
}