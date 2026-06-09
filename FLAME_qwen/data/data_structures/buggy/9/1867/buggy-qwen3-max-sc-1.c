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
                j = 0; // @@ [Resetting j to 0 inside the loop causes infinite loop or incorrect traversal because it restarts the inner loop from the beginning every time a connection is found, potentially revisiting already counted segments and violating the constraint that no three segments share an endpoint. This leads to overcounting or infinite loops in some cases.]
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