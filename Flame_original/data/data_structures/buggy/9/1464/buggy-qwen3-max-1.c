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
            if (point[j].x[0] == point[position].y[0] && point[j].x[1] == point[position].y[1]) { // @@ [Incorrect endpoint comparison: should compare point[j].x[0] with point[position].y[0] AND point[j].y[0] with point[position].y[1], but the current code compares x[1] instead of y[0]; also, the structure stores first endpoint in x[0],x[1] and second in y[0],y[1], so connection condition is wrong]
                length++;
                position = j;
            }
        }//see
        if (length > max) {
            max = length;
            nx = point[i].x[0];
            ny = point[i].x[1]; // @@ [Wrong starting point coordinates: should be (x[0], y[0]) of the first segment, but x[1] is used for y-coordinate which is actually the y of the first endpoint stored in x[1]; however, input reads as x0,y0,x1,y1 into x[0],x[1],y[0],y[1], so this is correct for starting point. But the real issue is in the connection logic above.]
        }//renew
    }
}

int main()
{
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d%d%d%d", &point[i].x[0], &point[i].x[1], &point[i].y[0], &point[i].y[1]);
    }
    reline; // @@ [Function call missing parentheses: should be reline() to actually call the function; without (), it's just a reference to the function pointer and does nothing]
    readpoints; // @@ [Function call missing parentheses: should be readpoints() to actually call the function; without (), it's just a reference to the function pointer and does nothing]
    printf("%d %d %d", max, nx, ny);
}