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
    duan* d = (duan*)c; // @@ Error: This should be `duan* d = (duan*)b;` to correctly compare two different elements. As written, it compares the same element to itself, making the sort ineffective.
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
        for (j = 0; j < N; j++) {
            if (xian[i].x2 == xian[j].x1 && xian[i].y2 == xian[j].y1) {
                xian[i].count++;
                xian[i].x2 =xian[j].x2;
                xian[i].y2 = xian[j].y2;
                // @@ Error: This loop does not correctly build chains. It modifies xian[i] while iterating, and may count segments multiple times or miss connections because it doesn't skip already-used segments. Also, it doesn't handle the case where multiple segments connect to the same endpoint (though constraints say no three share an endpoint, but two can). The algorithm should track which segments are used and properly extend the chain.
            }
        }
    }
    qsort(xian, N, sizeof(xian[0]), cup2);
    printf("%d %d %d",xian[0].count,xian[0].x1,xian[0].y1);

    return 0;
}