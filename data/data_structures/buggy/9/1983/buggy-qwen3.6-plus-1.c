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
        for (int j = 0; j < n; j++) { // @@ The loop iterates only once without restarting after a match, failing to traverse chains longer than 2 segments. It should reset j (e.g., j = -1) after finding a connection.
            if (headx == dot[j].x2 && heady == dot[j].y2 ) { // @@ Incorrectly attempts to extend the chain backward, violating the constraint that x-coordinates must be strictly increasing. Only forward extension from the tail is valid.
                headx = dot[j].x1; // @@ Modifying head during a single pass without restarting causes incorrect chain traversal and length calculation.
                heady = dot[j].y1; // @@ Same as above.
                current++; // @@ Same as above.
            } else if (tailx == dot[j].x1 && taily == dot[j].y1) { // @@ Should only check for forward extension, and must restart the loop (j = -1) to correctly count all connected segments in the chain.
                tailx = dot[j].x2; // @@ Without restarting the loop, subsequent segments in the chain will be missed if they appear earlier in the array.
                taily = dot[j].y2; // @@ Same as above.
                current++; // @@ Same as above.
            }
        }
        if (max < current) {
            max = current;
            resultx = headx; // @@ If backward chaining logic was executed, headx would be incorrect. The starting point should always be dot[i].x1.
            resulty = heady; // @@ Same as above.
        }

    }
    printf("%d %d %d", max, resultx, resulty);
    return 0;
}