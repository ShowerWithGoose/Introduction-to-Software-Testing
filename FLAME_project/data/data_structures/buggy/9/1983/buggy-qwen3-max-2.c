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
        for (int j = 0; j < n; j++) {
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
    printf("%d %d %d", max, resultx, resulty); // @@ [The algorithm only performs a single pass to extend the chain in both directions, but it fails to recursively or iteratively continue extending when new segments are added. This causes it to miss longer chains that require multiple extension steps. For example, after extending the tail once, it doesn't check again if the new tail can be further extended by other segments. Similarly for the head. Thus, the count 'current' is underestimated.]
    return 0;
}