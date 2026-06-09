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
        for (int j = 0; j <= index; j++) {
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
        for (int i = 0; i <= index; i++) {
            if (lines[i].num == 0)continue;
            for (int j = i + 1; j <= index; j++) {
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
    for (int i = 0; i <= index; i++) {
        if (lines[i].num > lines[longest_index].num) {
            longest_index = i;
        }
    }
    printf("%d %d %d", lines[longest_index].num, lines[longest_index].start.x, lines[longest_index].start.y); // @@ [The output format requires a newline at the end, but this printf does not include '\n', which may cause presentation errors or mismatched output in strict checkers. However, the reported error is "Compilation Error: gcc not found", which is not a code issue but an environment problem. Since the instruction says to annotate only actual code errors that explain the failure, and the test case shows a compilation error due to missing compiler, there is no actual bug in the code causing a logical/runtime error. But note: the array 'lines' is of fixed size 100, while problem constraints allow up to 200 segments as per reference program. This could cause buffer overflow if input >100. Also, 'index' starts at 0 and increments after assigning to lines[index], so max valid index is 99 for 100 elements. If num > 100, this overflows. The reference uses 200. So the real error is insufficient array size.]
    return 0;
}