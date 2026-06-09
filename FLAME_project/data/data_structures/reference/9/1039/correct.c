#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct LINE {
    int x1;
    int y1;
    int x2;
    int y2;
    int num;
};

int cmp(const void* p1, const void* p2) {
    struct LINE* x = (struct LINE*)p1;
    struct LINE* y = (struct LINEe*)p2;
    if (x->x1 != y->x1)
        return (x->x1 > y->x1) ? -1 : 1;
    return (x->y1 > y->y1) ? -1 : 1;
};

int main() {
    int n, i, j;
    int max = 0, flag = 0;
    struct LINE line[105];
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d%d%d%d", &line[i].x1, &line[i].y1, &line[i].x2, &line[i].y2);
        line[i].num = 1;
    }
    qsort(line, n, sizeof(line[0]), cmp);  //坐标从大到小排序

    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (line[i].x1 != line[j].x2 || line[i].y1 != line[j].y2)
                continue;
            else {
                line[j].num += line[i].num;
            }
        }
    }

    for (i = 0; i < n; i++) {
        if (line[i].num > max) {
            flag = i;
            max = line[i].num;
        }
    }
    printf("%d %d %d",max,line[flag].x1,line[flag].y1);
    return 0;
}
