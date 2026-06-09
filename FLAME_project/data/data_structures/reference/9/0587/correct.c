#include <stdio.h>
#include <stdlib.h>

int b[111][4];
int a[111][3];
int qi[111][2];

int cmp(const void *a, const void *b){
    int *a1 = (int*) a;
    int *b1 = (int*) b;
    return a1[0]-b1[0];
}

int main()
{
    int n; scanf("%d", &n);
    int max = 1, maxi = -1;
    for(int i = 0; i < n; i++){
        int x1, y1, x2, y2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        b[i][0] = x1; b[i][1] = y1; b[i][2] = x2; b[i][3] = y2;
    }
    qsort(b, n, sizeof(b[0]), cmp);
    int b1 = 0;
    for(int i = 0; i < n; i++){
        int x1, y1, x2, y2;
        x1 = b[i][0]; y1 = b[i][1]; x2 = b[i][2]; y2 = b[i][3];
        int is = 1;
        for(int j = 0; j < b1; j++){
            if(x1 == a[j][0] && y1 == a[j][1]){
                a[j][0] = x2; a[j][1] = y2; a[j][2]++;
                if(a[j][2] > max){
                    max = a[j][2];
                    maxi = j;
                }
                break;
            }
        }
        if(is == 1){
            a[b1][0] = x2; a[b1][1] = y2; a[b1][2] = 1;
            qi[b1][0] = x1; qi[b1][1] = y1;
            b1++;
        }
    }
    if(maxi >= 0){
        printf("%d %d %d\n", max, qi[maxi][0], qi[maxi][1]);
    }
//    if(maxi == -1) printf("1\n");
    return 0;
}

