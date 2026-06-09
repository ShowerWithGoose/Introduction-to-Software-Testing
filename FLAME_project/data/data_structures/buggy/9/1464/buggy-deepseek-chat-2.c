#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define len 128
int length, position, max = 0, nx, ny, n, i, j, flag = 0;

struct point
{
    int x[2];
    int y[2];
}point[len], temp;

void reline() {
    for (i = 0; i < n; i++) {
        flag = 0; //reset
        for (j = i + 1; j < n; j++) {
            if (point[j].x[0] < point[i].x[0]) {
                temp = point[j];
                point[j] = point[i];
                point[i] = temp;
                flag = 1;
            }
        }
        if (flag == 0)
            break;
    }

}
void readpoints() {
    for (i = 0; i < n; i++) {
        length = 1;
        position = i;
        for (j = i + 1; j < n; j++) {
            if (point[j].x[0] == point[position].y[0] && point[j].x[1] == point[position].y[1]) { // @@ [Error: The condition uses point[j].x[1] which is the second x-coordinate (endpoint x), but should compare the starting point of the next segment (point[j].x[0], point[j].x[1]) with the endpoint of the current segment (point[position].y[0], point[position].y[1]). However, the struct stores x[0], x[1] as first endpoint (x,y) and y[0], y[1] as second endpoint (x,y). So the correct comparison should be: point[j].x[0] == point[position].y[0] && point[j].x[1] == point[position].y[1] is actually correct for matching the start of segment j with the end of segment position. But the bug is that the function readpoints() is never called because in main() it is written as "readpoints;" without parentheses, so it's just a statement that does nothing.]
                length++;
                position = j;
            }
        }//see
        if (length > max) {
            max = length;
            nx = point[i].x[0];
            ny = point[i].x[1];
        }//renew
    }
}

int main()
{
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d%d%d%d", &point[i].x[0], &point[i].x[1], &point[i].y[0], &point[i].y[1]);
    }
    reline; // @@ [Error: Missing parentheses to call the function. Should be "reline();"]
    readpoints; // @@ [Error: Missing parentheses to call the function. Should be "readpoints();"]
    printf("%d %d %d", max, nx, ny);
}