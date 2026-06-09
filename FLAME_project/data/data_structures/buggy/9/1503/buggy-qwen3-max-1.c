#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct duans {
    int x1;
    int y1;
    int x2;
    int y2;
    int count;
}duan;
int cup1(const void* a, const void* b) {
    duan* c = (duan *) a;
    duan* d= (duan*)b;
    if (c->x1 != d->x1) {
        return (c->x1 - d->x1);
    }
    else {
        return (c->y1 - d->y1);
    }
}
int cup2(const void* a, const void* b) {
    duan* c = (duan*)a;
    duan* d = (duan*)c; // @@ [Typo: 'd' should be assigned from 'b', not 'c'. This causes incorrect sorting in cup2, leading to wrong selection of the longest chain.]
    return (d->count - c->count);
}
int main() {
    
    duan xian[100];
    int i = 0, j = 0;
    int N = 0;
    scanf("%d", &N);
    for (i = 0; i < N; i++) {
        scanf("%d %d %d %d", &xian[i].x1, &xian[i].y1,& xian[i].x2,& xian[i].y2);
        xian[i].count = 1;
    }
    qsort(xian, N, sizeof(xian[0]), cup1);
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) { // @@ [The nested loop does not correctly simulate chaining because it doesn't track visited segments or ensure sequential linking. It may overcount or link non-consecutive segments multiple times. Also, it modifies x2/y2 which affects future comparisons incorrectly.]
            if (xian[i].x2 == xian[j].x1 && xian[i].y2 == xian[j].y1) {
                xian[i].count++;
                xian[i].x2 =xian[j].x2;
                xian[i].y2 = xian[j].y2;

            }
        }
    }
    qsort(xian, N, sizeof(xian[0]), cup2);
    printf("%d %d %d",xian[0].count,xian[0].x1,xian[0].y1);

    return 0;
}