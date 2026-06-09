#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct s {
    int x;
    int y;
};
typedef struct s S;
typedef struct s *Sptr;
S a[1000], b[1000], c[1000];
char d;

int cmp(const void *p1, const void *p2);

int main() {
//    freopen("a.in", "r", stdin);
//    freopen("a.out", "w", stdout);
    int i, j, k = 0, a_cnt = 0, b_cnt = 0, c_cnt = 0;
    for (i = 0; d != '\n'; i++) {
        scanf("%d%d%c", &a[i].x, &a[i].y, &d);
        a_cnt++;
    }
    d = '\0';
//    for (i = 0; i < a_cnt; i++) {
//        printf("%d %d ", a[i].x, a[i].y);
//    }
//    printf("\n");
    for (i = 0; scanf("%d%d", &b[i].x, &b[i].y) != EOF; i++) {
        b_cnt++;
    }
//    for (i = 0; i < b_cnt; i++) {
//        printf("%d %d ", b[i].x, b[i].y);
//    }
    for (i = 0; i < a_cnt; i++) {
        for (j = 0; j < b_cnt; j++) {
            c[k].x = a[i].x * b[j].x;
            c[k].y = a[i].y + b[j].y;
            k++;
            c_cnt++;
        }
    }
    //降幂排列
    qsort(c, c_cnt, sizeof(S), cmp);
    //合并同指数项
    for (i = 0; i < c_cnt; i++) {
        for (j = i + 1; j < c_cnt; j++) {
            if (c[j].y == c[i].y) {
                c[i].x += c[j].x;
                c[j].x = 0;
            }
        }
    }
    for (i = 0; i < c_cnt; i++) {
        if (c[i].x == 0) continue;
        printf("%d %d ", c[i].x, c[i].y);
    }
    return 0;
}

int cmp(const void *p1, const void *p2) {
    Sptr a = (Sptr) p1;
    Sptr b = (Sptr) p2;
    return b->y - a->y; //指数降序排列
}

