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
    printf("%d %d %d"); // @@ [The printf format string expects three integer arguments, but none are provided, leading to undefined behavior. This is a runtime error, but given the test environment output "/bin/sh: 1: gcc: not found", it suggests a compilation or build issue. However, the actual code has a semantic error here: missing arguments in printf.]
    return 0;
}