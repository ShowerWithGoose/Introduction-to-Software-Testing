#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>

struct location {
    int x1;
    int y1;
    int x2;
    int y2;
    int num;     
};

typedef struct location Loc;
Loc l[2000];

int cmp(const void *p1, const void *p2);         //用于排序的函数 
int cmp2(const void *p1, const void *p2);

int main() 
{
    int n, i, j;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        l[i].num = 1;

    for (i = 0; i < n; i++) {
        scanf("%d %d %d %d", &l[i].x1, &l[i].y1, &l[i].x2, &l[i].y2);
    }

    qsort(l, n, sizeof(Loc), cmp2);

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (j == i) {
                continue;
            } else {
                if (l[j].x1 == l[i].x2 && l[j].y1 == l[i].y2) {
                    l[i].y2 = l[j].y2;
                    l[i].x2 = l[j].x2;
                    l[i].num = l[j].num+1; // @@ Error: This should be l[i].num += l[j].num to accumulate the count of merged segments, not just set to l[j].num+1, which loses previously merged segments.
                    l[j].x1 = 0, l[j].y1 = 0, l[j].x2 = 0, l[j].y2 = 0, l[j].num = 0;
                }
            }
        }
    }

    qsort(l, n, sizeof(Loc), cmp);

    printf("%d %d %d\n", l[n - 1].num, l[n - 1].x1, l[n - 1].y1);
    return 0;
}

int cmp(const void *p1, const void *p2) {
    struct location *a = (struct location *)p1;
    struct location *b = (struct location *)p2;
    return a->num - b->num;
}

int cmp2(const void *p1, const void *p2) {
    struct location *a = (struct location *)p1;
    struct location *b = (struct location *)p2;
    if (a->x1 != b->x1)
        return a->x1 - b->x1;
    else
        return a->y1 - b->y2; // @@ Error: This should compare a->y1 and b->y1 for consistent sorting by starting point; comparing y1 to y2 is incorrect and may cause incorrect ordering.
}