#include <stdio.h>

typedef struct {
    int v1x;
    int v1y;
    int v2x;
    int v2y;
} line;

int main() {
    int n, num = 1, max = 1, m = 0;
    scanf("%d", &n);
    line s[n];
    int a[n];
    line r;
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d %d", &s[i].v1x, &s[i].v1y, &s[i].v2x, &s[i].v2y);
    }
    for (int i = 0; i < n; i++) {
        r = s[i];
        for (int j = 0; j < n; j++) {
            if ((r.v2x == s[j].v1x) && (r.v2y == s[j].v1y)) {
                num++;
                r = s[j];
                j = 0; // @@ Setting j to 0 causes the next iteration to start at j=1, skipping the first element; should be j = -1 to restart from j=0 after increment.
            }
        }
        a[i] = num;
        num = 1;
    }
    for (int i = 0; i < n; i++) {
        if (a[i] > max) {
            max = a[i];
            m = i;
        }
    }
    printf("%d %d %d", max, s[m].v1x, s[m].v1y);
    return 0;
}