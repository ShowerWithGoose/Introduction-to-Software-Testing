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
        for (int j = 0; j <= index; j++) { // @@ The loop condition `j <= index` accesses uninitialized memory when `j == index` and no match is found in previous iterations, or causes logic errors. It should be `j < index` to check existing segments, and handle the "not found" case separately or ensure `index` is handled correctly. Specifically, if `j` reaches `index`, it means no existing segment matched. The current code tries to match against `lines[index]` which might be garbage or partially initialized if `index` hasn't been incremented yet for this new segment. More critically, if a match is found at `j < index`, it breaks. If no match is found, it falls through to `j == index`. However, the loop bound `<= index` combined with the logic inside is fragile. The standard approach is to iterate `j < index` to find a match. If no match is found after the loop, add a new segment. The current structure mixes search and insertion in a way that can access invalid data if `index` is 0 initially (accessing `lines[0]` before initialization if the loop runs). Actually, if `index` is 0, `j` goes from 0 to 0. `lines[0]` is uninitialized. This is undefined behavior.
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
        for (int i = 0; i <= index; i++) { // @@ Similar to above, `i <= index` iterates one past the last valid element. `lines[index]` is not a valid initialized segment if `index` represents the count of segments. It should be `i < index`.
            if (lines[i].num == 0)continue;
            for (int j = i + 1; j <= index; j++) { // @@ Similarly, `j <= index` accesses invalid memory. It should be `j < index`.
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
    for (int i = 0; i <= index; i++) { // @@ Similarly, `i <= index` accesses invalid memory. It should be `i < index`.
        if (lines[i].num > lines[longest_index].num) {
            longest_index = i;
        }
    }
    printf("%d %d %d", lines[longest_index].num, lines[longest_index].start.x, lines[longest_index].start.y);
    return 0;
}