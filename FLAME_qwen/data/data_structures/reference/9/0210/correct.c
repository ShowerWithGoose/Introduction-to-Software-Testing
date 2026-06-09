#include <stdio.h>

typedef struct pos {
    int x;
    int y;
} pos;

typedef struct dot {
    pos dpos1;
    pos dpos2;
    int conditon;
} dot;

dot dots[105];

int main() {
    int n;
    scanf("%d", &n);
    int i;
    for (i = 0; i < n; i++) {
        scanf("%d %d %d %d", &dots[i].dpos1.x, &dots[i].dpos1.y,
              &dots[i].dpos2.x, &dots[i].dpos2.y);
        dots[i].conditon = 0;
    }
    int j, max = 0, maxx = 0, maxy = 0;
    for (i = 0; i < n; i++) {
        if (dots[i].conditon == 1) {
            continue;
        }
        int tempx = dots[i].dpos2.x;
        int tempy = dots[i].dpos2.y;
        int cnt = 1;
        for (j = 0; j < n; j++) {
            if (tempx == dots[j].dpos1.x && tempy == dots[j].dpos1.y) {
                tempx = dots[j].dpos2.x;
                tempy = dots[j].dpos2.y;
                dots[j].conditon = 1;
                cnt++;
                j = -1;
            }
        }
        if (cnt > max) {
            max = cnt;
            maxx = dots[i].dpos1.x;
            maxy = dots[i].dpos1.y;
        }
    }
    printf("%d %d %d", max, maxx, maxy);
    return 0;
}
