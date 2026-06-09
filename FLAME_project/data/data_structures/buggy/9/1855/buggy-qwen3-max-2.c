#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int x, y;
} Point;
typedef struct {
    int size; // @@ [Missing 'size' field in Segment struct causes undefined behavior when accessing segment->size later]
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
    printf("%d %d %d"); // @@ [Incorrect printf format: missing arguments and wrong number of format specifiers; should print max count and starting point coordinates]
    return 0;
}