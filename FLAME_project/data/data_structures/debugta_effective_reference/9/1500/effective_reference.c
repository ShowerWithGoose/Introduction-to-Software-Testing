#include <stdio.h>
#include <stdlib.h>

int arr1[111][4];
int arr3[111][3];
int qi[111][2];

int cmp(const void *arr3, const void *arr1){
    int *a1 = (int*) arr3;
    int *i = (int*) arr1;
    return a1[0]-i[0];
}

int main()
{
    int n; scanf("%d", &n);
    int max = 1, maxi = -1;
    for(int i = 0; i < n; i++){
        int x1, y1, x2, y2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        arr1[i][0] = x1; arr1[i][1] = y1; arr1[i][2] = x2; arr1[i][3] = y2;
    }
    qsort(arr1, n, sizeof(arr1[0]), cmp);
    int i = 0;
    for(int i = 0; i < n; i++){
        int x1, y1, x2, y2;
        x1 = arr1[i][0]; y1 = arr1[i][1]; x2 = arr1[i][2]; y2 = arr1[i][3];
        int is = 1;
        for(int j = 0; j < i; j++){
            if(x1 == arr3[j][0] && y1 == arr3[j][1]){
                arr3[j][0] = x2; arr3[j][1] = y2; arr3[j][2]++;
                if(arr3[j][2] > max){
                    max = arr3[j][2];
                    maxi = j;
                }
                break;
            }
        }
        if(is == 1){
            arr3[i][0] = x2; arr3[i][1] = y2; arr3[i][2] = 1;
            qi[i][0] = x1; qi[i][1] = y1;
            i++;
        }
    }
    if(maxi >= 0){
        printf("%d %d %d\n", max, qi[maxi][0], qi[maxi][1]);
    }
//    if(maxi == -1) printf("1\n");
    return 0;
}

