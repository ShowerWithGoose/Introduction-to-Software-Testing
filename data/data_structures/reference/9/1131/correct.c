#include <stdio.h>
#include <math.h>
#include <stdlib.h>
void re( int n, int b[4]);
int a[101][4], b[4], n, x, y, xa, ya, z,i,j,k;
struct xianduan
{
	int x1;
	int x2;
	int y1;
	int y2;
}xd[102];
int main()
{
    scanf("%d", &n);
    for (i = 0; i < n; i++){
        scanf(" %d %d %d %d", &xd[i].x1, &xd[i].y1, &xd[i].x2, &xd[i].y2);
    }

    re(n, b);
    for (i = 0; i < n; i++){
        z = i;
        y = 0;
        for (j = i + 1; j < n; j++){
            if (xd[z].x2 == xd[j].x1){
                if (xd[z].y2 == xd[j].y1){
                    y++;
                    z = j;
                }
            }
        }
        if (y > x){
            x = y;
            xa = xd[i].x1;
            ya = xd[i].y1;
        }
    }
	printf("%d %d %d", x + 1, xa, ya);
    return 0;
}
void re(int n, int b[4]){
    for (i = 0; i < n; i++){
        for (j = i + 1; j < n; j++){
            if (xd[i].x1 > xd[j].x1){
                b[0]=xd[i].x1;
                b[1]=xd[i].y1;
                b[2]=xd[i].x2;
                b[3]=xd[i].y2;
                xd[i]=xd[j];
                xd[j].x1=b[0];
                xd[j].y1=b[1];
                xd[j].x2=b[2];
                xd[j].y2=b[3];
            }
        }
    }
}


