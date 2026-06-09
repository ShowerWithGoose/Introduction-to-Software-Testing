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
    printf("%d %d %d", max, resultx, resulty); // @@ [The algorithm only extends the chain by one step in each direction per outer loop iteration. It fails to recursively or iteratively follow the entire chain in both directions, leading to undercounting the total number of connected segments. For example, after extending the tail once, it doesn't check if the new tail can be further extended in subsequent iterations of the inner loop. Thus, long chains are not fully traversed.]
    return 0;
}