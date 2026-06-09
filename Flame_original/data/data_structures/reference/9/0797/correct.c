#include <stdio.h>

typedef struct line {
    int x1;
    int y1;
    int x2;
    int y2;
    int cnt;//以它为首的线段数
} line;
line lines[105];
int cnt = 0, max = 0;
int n, i, j;
int len[105];

int cmp(const void *a, const void *b) {
    line *aa = (line *)a;
    line *bb = (line *)b;
    return ((aa->x1)>(bb->x1)) ? 1: -1;
}
int main() {
    scanf("%d", &n);
    for(i = 0; i < n; i++)
        scanf("%d%d%d%d", &lines[i].x1, &lines[i].y1, &lines[i].x2, &lines[i].y2);
    //初始化数据
    for(i = 0; i < n; i++)
        lines[i].cnt = 1;

//    int start = 0;
//    scan(start);
    qsort(lines, n, sizeof(lines[0]), cmp);

    int cur;//当前最新的匹配线段
    for(i = 0; i < n; i++) {
        cur = i;
        for(j = i; j < n; j++) {
            if(lines[j].x1==lines[cur].x2 && lines[j].y1==lines[cur].y2) {//和上次匹配的线段匹配
                cur = j;//记为新的匹配线段
                lines[i].cnt++;
            }
        }
    }

    int max = 0, x, y;
    for(i = 0; i < n; i++)
        if(lines[i].cnt > max) {
            max = lines[i].cnt;
            x = lines[i].x1;
            y = lines[i].y1;
        }

    printf("%d %d %d", max, x, y);

    return 0;
}

