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
    printf("%d %d %d"); // @@ [The printf format string expects three integer arguments but none are provided, leading to undefined behavior and likely runtime or compilation issues depending on compiler settings.]
    return 0;
}