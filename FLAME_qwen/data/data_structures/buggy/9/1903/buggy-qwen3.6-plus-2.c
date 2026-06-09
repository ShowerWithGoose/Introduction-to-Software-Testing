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

Line lines[100]; // @@ Array size may be insufficient for the input constraints; reference program uses 200.

int main()
{
    int num = 0, index = 0;
    scanf("%d", &num);
    for (int i = 0; i < num; i++) {
        int x1, y1, x2, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        for (int j = 0; j <= index; j++) { // @@ Loop bound includes uninitialized index; should check lines[j].num > 0 before accessing coordinates.
            if (lines[j].start.x == x2 && lines[j].start.y == y2) { // @@ Missing check for lines[j].num > 0, may incorrectly match against uninitialized or cleared lines.
                lines[j].start.x = x1;
                lines[j].start.y = y1;
                lines[j].num++;
                break;
            }
            else if (lines[j].end.x == x1 && lines[j].end.y == y1) { // @@ Missing check for lines[j].num > 0, may incorrectly match against uninitialized or cleared lines.
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
        for (int i = 0; i <= index; i++) { // @@ Loop bound should be i < index to prevent out-of-bounds access on lines array.
            if (lines[i].num == 0)continue;
            for (int j = i + 1; j <= index; j++) { // @@ Loop bound should be j < index to prevent out-of-bounds access on lines array.
                if (lines[i].start.x == lines[j].end.x && lines[i].start.y == lines[j].end.y) { // @@ Missing check for lines[j].num > 0; merging with a cleared line corrupts the continuous segment geometry.
                    lines[i].start.x = lines[j].start.x;
                    lines[i].start.y = lines[j].start.y;
                    lines[i].num += lines[j].num;
                    lines[j].num = 0;
                    flag = 1;
                    break;
                }
                else if (lines[i].end.x == lines[j].start.x && lines[i].end.y == lines[j].start.y) { // @@ Missing check for lines[j].num > 0; merging with a cleared line corrupts the continuous segment geometry.
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
    for (int i = 0; i <= index; i++) { // @@ Loop bound should be i < index to prevent out-of-bounds access.
        if (lines[i].num > lines[longest_index].num) {
            longest_index = i;
        }
    }
    printf("%d %d %d", lines[longest_index].num, lines[longest_index].start.x, lines[longest_index].start.y);
    return 0;
}