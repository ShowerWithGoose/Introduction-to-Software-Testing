#include <malloc.h>
#include <stdio.h>
struct line {
    int startx;
    int starty;
    int endx;
    int endy;
    int flag;
    struct line *next;
};
struct line *first = NULL, *p, *q;
void getLine(int num) {
    int i;
    for (i = 1; i <= num; i++) {
        q = (struct line *)malloc(sizeof(struct line));
        scanf("%d %d %d %d", &q->startx, &q->starty, &q->endx, &q->endy);
        q->flag = 0;
        q->next = NULL;
        if (first == NULL)
            first = p = q;
        else {
            p->next = q;
            p = p->next;
        }
    }
    p->next = first;
    p = first;
    return;
}
void compare(int num) {
    int count = 1, max = 0, tempx, tempy, x, y, maxx, maxy, i, countFlag = 0;
    while (countFlag < num) {
        if (p->flag == 0) {
            x = p->startx;
            tempx = p->endx;
            y = p->starty;
            tempy = p->endy;
            p->flag = 1;
            countFlag++;
            for (i = 1; i < num; i++) {
                p = p->next;
                if (p->startx == tempx && p->starty == tempy) {
                    count++;
                    tempx = p->endx;
                    tempy = p->endy;
                    if (p->flag == 0) {
                        p->flag = 1;
                        countFlag++;
                    }
                    if (tempx == x && tempx == y) break;
                    i = 1;
                } else if (p->endx == x && p->endy == y) {
                    count++;
                    x = p->startx;
                    y = p->starty;
                    if (p->flag == 0) {
                        p->flag = 1;
                        countFlag++;
                    }
                    if (tempx == x && tempx == y) break;
                    i = 1;
                }
            }
        }
        if (count > max) {
            max = count;
            maxx = x;
            maxy = y;
        }
        count = 1;
        p = p->next;
    }
    printf("%d %d %d", max, maxx, maxy);
    return;
}
int main() {
    int num;
    scanf("%d", &num);
    getLine(num);
    compare(num);
    return 0;
}
