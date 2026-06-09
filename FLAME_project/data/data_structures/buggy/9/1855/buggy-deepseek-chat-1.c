#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int x, y;
} Point;
typedef struct {
    Point start;
    Point end;
} Segment;
int main() {
    int n;
    scanf("%d", &n);
    Segment segments[n];
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d %d", &segments[i].start.x, &segments[i].start.y, &segments[i].end.x, &segments[i].end.y);
    }
    printf("%d %d %d"); // @@ The printf statement is missing the arguments to print the actual values. It should print the number of segments, and the x and y coordinates of the starting point, but instead it prints garbage (uninitialized values) because no variables are passed. The correct output should be "2 12 12" based on the test case.
    return 0;
}