/*********************************************************************
    程序名:
    版权:
    作者:
    日期: 2024-03-19 19:21
    说明:

*********************************************************************/
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
typedef struct {
    int x1, y1;
    int x2, y2;
} xianduan;
xianduan a[105];
int mark[105];

int main() {

    int n;
    int x, y;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d%d%d", &a[i].x1, &a[i].y1, &a[i].x2, &a[i].y2);
    }
    int max = 0;

    for (int i = 0; i < n; i++) {
        int num = 1;
        mark[i] = 1;
        int jiaodian1x = a[i].x1, jiaodian1y = a[i].y1, jiaodian2x = a[i].x2, jiaodian2y = a[i].y2  ;
        for (int j = 0; j < n; j++) {
            if (mark[j] == 0) {
                if (jiaodian2x == a[j].x1 && jiaodian2y == a[j].y1  ) {
                    mark[j] = 1;
                    num++;
                    jiaodian2x = a[j].x2;
                    jiaodian2y = a[j].y2 ;
                }
                if (jiaodian1x == a[j].x2 && jiaodian1y == a[j].y2  ) {
                    mark[j] = 1;
                    num++;
                    jiaodian1x = a[j].x1;
                    jiaodian1y = a[j].y1 ;
                }
            }
        }
        if (num > max) {
            max = num;
            x = jiaodian1x;
            y = jiaodian1y;
        }
        for (int m = 0; m < n; m++) {
            mark[m] = 0;
        }
    }
    printf("%d %d %d", max, x, y);
    return 0;
}