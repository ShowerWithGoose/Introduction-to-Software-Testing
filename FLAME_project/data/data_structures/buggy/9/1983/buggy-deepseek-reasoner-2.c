#include <stdio.h>


struct stu {
    int x1;
    int y1;
    int x2;
    int y2;
} dot[105];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d%d%d", &dot[i].x1, &dot[i].y1, &dot[i].x2, &dot[i].y2);
    }
    int headx, heady, tailx, taily, resultx, resulty;
    int max = 0;
    for (int i = 0; i < n; i++) {
        int current = 1;
        headx = dot[i].x1;
        heady = dot[i].y1;
        tailx = dot[i].x2;
        taily = dot[i].y2;
        for (int j = 0; j < n; j++) { // @@ The loop only checks each segment once, but after updating head or tail, previously seen segments that could connect are missed. This makes the algorithm unable to extend the chain beyond immediate neighbors, leading to an incomplete count and wrong starting point.
            if (headx == dot[j].x2 && heady == dot[j].y2 ) {
                headx = dot[j].x1;
                heady = dot[j].y1;
                current++;
            } else if (tailx == dot[j].x1 && taily == dot[j].y1) {
                tailx = dot[j].x2;
                taily = dot[j].y2;
                current++;
            }
        }
        if (max < current) {
            max = current;
            resultx = headx;
            resulty = heady;
        }

    }
    printf("%d %d %d", max, resultx, resulty);
    return 0;
}