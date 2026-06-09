#include <stdio.h>
#include <stdlib.h>

typedef struct Point {
    int x;
    int y;
} Point;

typedef struct Line {
    int num;
    Point start;
    Point end;
} Line;

Line lines[100];

int main()
{
    int num = 0, index = 0;
    scanf("%d", &num);
    for (int i = 0; i < num; i++) {
        int x1, y1, x2, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        for (int j = 0; j <= index; j++) { // @@ The loop condition `j <= index` accesses uninitialized memory when `j == index` and no match is found in previous iterations. It should be `j < index` to only check existing segments, relying on the `else if (j == index - 1)` or similar logic to add new ones, or simply `j < index` and handle addition outside. However, the current logic uses `j == index` inside to add. If `index` is 0, `j` goes from 0 to 0. `lines[0]` is uninitialized. The check `lines[j].start.x == x2` reads garbage. This leads to undefined behavior and incorrect merging or creation of segments.
            if (lines[j].start.x == x2 && lines[j].start.y == y2) {
                lines[j].start.x = x1;
                lines[j].start.y = y1;
                lines[j].num++;
                break;
            }
            else if (lines[j].end.x == x1 && lines[j].end.y == y1) {
                lines[j].end.x = x2;
                lines[j].end.y = y2;
                lines[j].num++;
                break;
            }
            else if (j == index) {
                lines[index].start.x = x1;
                lines[index].start.y = y1;
                lines[index].end.x = x2;
                lines[index].end.y = y2;
                lines[index].num = 1;
                index++;
                break;
            }
        }
    }
    int flag = 1;
    while (flag) {
        flag = 0;
        for (int i = 0; i <= index; i++) { // @@ Similar to above, `i <= index` iterates one past the last valid segment index (`index - 1`). `lines[index]` might be uninitialized or contain garbage if `index` was incremented but that slot wasn't the target of the outer loop's valid range. It should be `i < index`.
            if (lines[i].num == 0)continue;
            for (int j = i + 1; j <= index; j++) { // @@ Similarly, `j <= index` accesses potentially uninitialized memory. It should be `j < index`.
                if (lines[i].start.x == lines[j].end.x && lines[i].start.y == lines[j].end.y) {
                    lines[i].start.x = lines[j].start.x;
                    lines[i].start.y = lines[j].start.y;
                    lines[i].num += lines[j].num;
                    lines[j].num = 0;
                    flag = 1;
                    break;
                }
                else if (lines[i].end.x == lines[j].start.x && lines[i].end.y == lines[j].start.y) {
                    lines[i].end.x = lines[j].end.x;
                    lines[i].end.y = lines[j].end.y;
                    lines[i].num += lines[j].num;
                    lines[j].num = 0;
                    flag = 1;
                    break;
                }
            }
        }
    }
    int longest_index = 0;
    for (int i = 0; i <= index; i++) { // @@ Again, `i <= index` accesses out-of-bounds/uninitialized memory. Should be `i < index`.
        if (lines[i].num > lines[longest_index].num) {
            longest_index = i;
        }
    }
    printf("%d %d %d", lines[longest_index].num, lines[longest_index].start.x, lines[longest_index].start.y);
    return 0;
}