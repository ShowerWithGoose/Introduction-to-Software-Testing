#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
void arrange(int a[102][4], int n, int flag[4]);
int a[102][4],flag[4],n,max,num,x,y,m;

int main()
{
    int i,j;
    scanf("%d", &n);
    for (i = 0; i < n; i++){
        scanf(" %d%d%d%d", &a[i][0], &a[i][1], &a[i][2], &a[i][3]);
    }
    arrange(a, n, flag);
    for (i = 0; i < n; i++){
        m= i,num = 0;
        for (j = i + 1; j < n; j++){
            if (a[m][2] == a[j][0]){
                if (a[m][3] == a[j][1]){
                    num++;
                    m = j;
                }
            }
        }
        if (num > max){
            max = num;
            x = a[i][0];
            y = a[i][1];
        }
    }
    printf("%d %d %d", max + 1, x, y);
    return 0;
}

void arrange(int a[101][4], int n, int flag[4])
{
    int i,j,k;
    for (i = 0; i < n; i++){
        for (j = i + 1; j < n; j++){
            if (a[i][0] > a[j][0]){
                for (k = 0; k < 4; k++){
                    flag[k] = a[i][k];
                }
                for (k = 0; k < 4; k++){
                    a[i][k] = a[j][k];
                }
                for (k = 0; k < 4; k++){
                    a[j][k] = flag[k];
                }
            }
        }
    }
}

