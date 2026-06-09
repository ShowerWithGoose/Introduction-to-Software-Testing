#include <stdio.h>
struct line {
    int bx;
    int by;
    int ex;
    int ey;
    int a;
};
struct line l[105], t;
void main()
{
    int i, j, n, q, max;
    scanf ("%d", &n);
    for (i = 0; i < n; i++) {
        l[i].a = 1;
    }
    for (i = 0; i < n; i++) {
        scanf ("%d%d%d%d", &l[i].bx, &l[i].by, &l[i].ex, &l[i].ey);
    }
    for (i = 0; i < n - 1; i++) 
        for (j = 0; j < n - i - 1; j++) {
            if (l[j].bx > l[j+1].bx) {
                t = l[j];
                l[j] = l[j+1];
                l[j+1] = t;
            }
        }
    for (i = 0; i < n; i++) 
        for (j = i+1; j < n; j++) {
            if (l[i].ex == l[j].bx && l[i].ey == l[j].by) {
                l[j].a = l[i].a + 1;
                l[j].bx = l[i].bx;
                l[j].by = l[i].by;
                break;
            }
        }
    max = l[0].a;
    q = 0;
    for (i = 1; i < n; i++) {
        if (l[i].a > max) {
            max = l[i].a;
            q = i;
        }
    }
    printf ("%d %d %d", l[q].a, l[q].bx, l[q].by);
    return ;
}
