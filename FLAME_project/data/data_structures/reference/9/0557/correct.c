#include <stdio.h>
#include <stdlib.h>

typedef struct pot{
    int x;
    int y;
} pot;
typedef struct seg{
    pot p1;
    pot p2;
    int len;
} seg;
seg line[110];
seg max;
int cmppot(const void *a, const void *b);

int main() {
    int i, j;
    int n;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d%d%d%d", &line[i].p1.x, &line[i].p1.y, &line[i].p2.x, &line[i].p2.y);
        line[i].len = 1;
        
    }
    qsort(line, n, sizeof(seg), cmppot);
    for (i = 0; i < n; i++) {
        for (j = i+1; j < n; j++) {
            if (line[i].p2.x == line[j].p1.x && line[i].p2.y == line[j].p1.y) {
                line[i].len++;
                line[i].p2 = line[j].p2;
                if (max.len < line[i].len) {
                    max = line[i];
                }
            }
        }
    }
    printf("%d %d %d\n", max.len, max.p1.x, max.p1.y);
    return 0;
}

int cmppot(const void *a, const void *b){
    seg *m = (seg*)a;
    seg *n = (seg*)b;
    if (m->p1.x != n->p1.x) {
        return (m->p1.x) - (n->p1.x);
    }else{
        return (m->p1.y)- (n->p1.y);
    }
}

/*
10

80 75 125 75
60 40 80 55
80 55 90 20
140 120 195 205
10 111 70 165
22 35 43 43
22 175 80 205
43 43 60 40
90 20 125 60
70 165 140 120
 */

