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
            if (point[j].x[0] == point[position].y[0] && point[j].x[1] == point[position].y[1]) { // @@ Error: Incorrect field access. Should compare point[j].x[0] with point[position].x[1] and point[j].y[0] with point[position].y[1] to check if segment j starts where segment position ends. The struct stores x[0],x[1] as first endpoint and y[0],y[1] as second endpoint, but the logic uses y[0] and y[1] incorrectly.
                length++;
                position = j;
            }
        }//see
        if (length > max) {
            max = length;
            nx = point[i].x[0];
            ny = point[i].x[1]; // @@ Error: Should store point[i].y[0] and point[i].y[1] for the starting point's y-coordinate, but here x[1] is used which is the x-coordinate of the first endpoint, not the y-coordinate.
        }//renew
    }
}

int main()
{
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d%d%d%d", &point[i].x[0], &point[i].x[1], &point[i].y[0], &point[i].y[1]); // @@ Error: Input order is wrong. The problem specifies endpoints as (x1,y1) and (x2,y2), but here x[0],x[1] are read as two x values and y[0],y[1] as two y values, mixing coordinates. Should read as point[i].x[0], point[i].y[0], point[i].x[1], point[i].y[1].
    }
    reline; // @@ Error: Missing parentheses to call function. Should be reline();
    readpoints; // @@ Error: Missing parentheses to call function. Should be readpoints();
    printf("%d %d %d", max, nx, ny);
}