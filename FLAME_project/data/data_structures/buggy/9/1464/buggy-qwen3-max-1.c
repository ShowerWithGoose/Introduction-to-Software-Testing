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
            if (point[j].x[0] == point[position].y[0] && point[j].x[1] == point[position].y[1]) { // @@ [Incorrect endpoint comparison: should compare point[j].x[0] with point[position].y[0] AND point[j].x[1] with point[position].y[1], but the structure stores endpoints as x[0],x[1] for first point and y[0],y[1] for second. However, the logic assumes segments are sorted and chained only forward, but fails to consider that a segment might connect backward or that the sort is incomplete. Also, the chaining logic only checks immediate next segments in array order, not all possible continuations.]
                length++;
                position = j;
            }
        }//see
        if (length > max) {
            max = length;
            nx = point[i].x[0];
            ny = point[i].x[1]; // @@ [Correctly captures starting point, but since 'max' may remain 0 due to failed chaining, this may never update properly. However, the main issue is in the chaining condition above.]
        }//renew
    }
}

int main()
{
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d%d%d%d", &point[i].x[0], &point[i].x[1], &point[i].y[0], &point[i].y[1]);
    }
    reline; // @@ [Function call missing parentheses: should be reline(); This causes the function not to be called, so the array remains unsorted, breaking the chaining logic which relies on ordering by starting x-coordinate.]
    readpoints; // @@ [Function call missing parentheses: should be readpoints(); This causes the function not to be called, so max, nx, ny remain at initial values (0,0,0), leading to output "0 0 0".]
    printf("%d %d %d", max, nx, ny);
}