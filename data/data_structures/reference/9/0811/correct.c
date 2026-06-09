#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct line {
    int x1;
    int y1;
    int x2;
    int y2;
    int cnt;
};
typedef struct line Line;
typedef struct line *Lineptr;
Line a[105];

int cmp(const void *p1, const void *p2);

int main() {
//    freopen("a.in", "r", stdin);
//    freopen("a.out", "w", stdout);
    int n, i, j, max_cnt = 1, max_i;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        a[i].cnt = 1;
        scanf("%d %d %d %d", &a[i].x1, &a[i].y1, &a[i].x2, &a[i].y2);
    }
    qsort(a, n, sizeof(Line), cmp);
//    for (i = 0; i < n; i++) {
//        printf("%d %d %d %d\n", a[i].x1, a[i].y1, a[i].x2, a[i].y2);
//    }
    for (i = 0; i < n; i++) {
        int end_x2 = a[i].x2, end_y2 = a[i].y2;
        for (j = 0; j < n; j++) {
            if (j == i) continue;
            if (end_x2 == a[j].x1 && end_y2 == a[j].y1) {
                a[i].cnt++;
                end_x2 = a[j].x2;
                end_y2 = a[j].y2;
            }
        }
    }
    for (i = 0; i < n; i++) {
        if (a[i].cnt > max_cnt) {
            max_cnt = a[i].cnt;
            max_i = i;
        }
    }
    printf("%d %d %d", a[max_i].cnt, a[max_i].x1, a[max_i].y1);
    return 0;
}

int cmp(const void *p1, const void *p2) {
    Lineptr a = (Lineptr) p1;
    Lineptr b = (Lineptr) p2;
    if (a->x1 != b->x1) return a->x1 - b->x1;
    else return a->y1 - b->y1;
}
