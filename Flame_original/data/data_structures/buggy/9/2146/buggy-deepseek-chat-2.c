#include <stdio.h>
#include <stdlib.h>

typedef struct line {
    int startx;
    int starty;
    int endx;
    int endy;
    int counter;//连续线段数量
} line;

int cmp(const void *e1, const void *e2) {
    line *data1 = (line *)e1;
    line *data2 = (line *)e2;
    return data1->endx - data2->endx;
}

int main() {
    int n;//线段数
    scanf("%d", &n);
    line *gather = malloc(sizeof(line) * n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d%d%d", &gather[i].startx, &gather[i].starty, &gather[i].endx, &gather[i].endy);
        gather[i].counter = 1;//初始化
    }
    qsort(gather, n, sizeof(line), cmp);
    for (int i = n - 1; i > 0; i--) { //此时第“0”个不需要遍历
        for (int j = i - 1; gather[j].endx >= gather[i].startx; j--) { // @@ [The loop condition may cause out-of-bounds access when j becomes -1, and the logic does not correctly handle the case where multiple segments can connect in sequence; it should iterate through all possible j values from i-1 down to 0, not stop prematurely based on endx comparison.]
            //能连在一起的必要条件是前一个线段终点的横坐标大于等于后一个的
            if (gather[i].startx == gather[j].endx && gather[i].starty == gather[j].endy) {
                gather[j].counter += gather[i].counter;
                break; // @@ [Using break here prevents checking other segments that might also connect to gather[i], which is incorrect because only one segment can connect to gather[i]'s start point, but the break should not be used as it stops the loop prematurely; however, the main issue is the loop condition.]
            }
        }
    }
    int maxnum = 0; // @@ [Variable name mismatch: declared as 'maxnum' but used as 'max_num' later, causing compilation error.]
    line target;
    for (int i = 0; i < n; i++) {
        if (max_num < gather[i].counter) { // @@ [Variable 'max_num' is not declared; should be 'maxnum'.]
            max_num = gather[i].counter; // @@ [Same issue: 'max_num' should be 'maxnum'.]
            target = gather[i];
        }
    }
    printf("%d %d %d", max_num, target.startx, target.starty); // @@ [Variable 'max_num' not declared; should be 'maxnum'.]
    return 0;
}