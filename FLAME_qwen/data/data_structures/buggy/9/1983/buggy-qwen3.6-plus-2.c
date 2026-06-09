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
        for (int j = 0; j < n; j++) { // @@ The loop only iterates once over the segments, failing to extend the chain beyond one connection. It should reset j (e.g., j = -1) after finding a match to continue searching for the next segment in the continuous line.
            if (headx == dot[j].x2 && heady == dot[j].y2 ) { // @@ The problem specifies x1 < x2, meaning segments are directed forward. Checking the head endpoint for a connection is logically incorrect and unnecessary.
                headx = dot[j].x1; // @@ Incorrectly updates the starting point of the chain, which should remain fixed for the current iteration.
                heady = dot[j].y1; // @@ Incorrectly updates the starting point of the chain.
                current++; // @@ Incorrectly increments count for a backward connection.
            } else if (tailx == dot[j].x1 && taily == dot[j].y1) { // @@ Correctly checks for a forward connection, but without resetting the loop index, it will miss subsequent segments in the chain.
                tailx = dot[j].x2; // @@ Updates the tail correctly, but the single-pass loop prevents finding further connected segments.
                taily = dot[j].y2; // @@ Updates the tail correctly, but the single-pass loop prevents finding further connected segments.
                current++; // @@ Increments count, but chain building stops prematurely due to lack of loop restart.
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