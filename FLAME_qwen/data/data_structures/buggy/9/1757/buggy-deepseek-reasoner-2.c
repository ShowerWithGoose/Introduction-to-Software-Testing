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
int count = 1;

int main() {
    int n;//Ïß¶ÎÊý
    int i = 0, j = 0;
    int count_max = 1, x, y; // @@ x and y are uninitialized; if the longest chain has length 1, they remain undefined, leading to undefined behavior.
    int x2, y2;
    line a[10]; // @@ array size is fixed at 10, but n can be larger (the reference program uses 150). This will cause buffer overflow for inputs with more than 10 segments.
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
            if (a[j].x1 == x2 && a[j].y1 == y2) { // @@ This greedy selection picks the first matching segment in sorted order. It does not consider that a different branch (starting at the same point but leading to a longer chain) might exist. This can produce a suboptimal chain length.
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
    printf("%d %d %d", count_max, x, y);


    return 0;
}