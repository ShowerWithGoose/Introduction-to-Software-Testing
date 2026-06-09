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
int count = 1; // @@ Global variable 'count' should be declared locally inside main to avoid unintended state persistence and potential logical errors across different test runs.

int main() {
    int n;//Ïß¶ÎÊý
    int i = 0, j = 0;
    int count_max = 1, x, y; // @@ Variables 'x' and 'y' are uninitialized. If the maximum count remains 1, printing them results in undefined behavior/garbage values.
    int x2, y2;
    line a[10]; // @@ Array size 10 is too small for typical inputs (reference uses 150). This will cause out-of-bounds memory access for n > 10.
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
    printf("%d %d %d", count_max, x, y); // @@ Missing newline character at the end of output, which may cause presentation/format errors on some judging systems.


    return 0;
}