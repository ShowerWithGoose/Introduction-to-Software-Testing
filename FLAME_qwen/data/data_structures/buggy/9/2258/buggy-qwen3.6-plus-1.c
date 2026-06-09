#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x1, y1;
    int x2, y2;
    int cou;
} S;

int compare(const void *a, const void *b) {
    S *sa = (S *)a;
    S *sb = (S *)b;
    return sa->x2 - sb->x2;
}

int main() {
    int n, i;
    scanf("%d", &n);
    S xian[n]; // @@ Variable length array may cause compilation error in strict C89 environments; consider using a fixed-size array or dynamic allocation.

    for (i = 0; i < n; i++)
        scanf("%d %d %d %d", &xian[i].x1, &xian[i].y1, &xian[i].x2, &xian[i].y2); // @@ Missing initialization of xian[i].cou to 1, leading to undefined behavior when accumulating counts.

    qsort(xian, n, sizeof(S), compare);
    for(int i=n-1;i>0;i--){
        for(int j=i-1;xian[j].x2>=xian[i].x1;j--){ // @@ Missing 'j >= 0' boundary check in loop condition causes out-of-bounds array access when j decrements below 0.
            if(xian[i].x1==xian[j].x2&&xian[j].y2==xian[i].y1){
                xian[j].cou+=xian[i].cou;
                break;
            }
        }
    }
    int maxl = 1;
    S start ; // @@ Variable 'start' is uninitialized; if no segment has cou > 1, it will contain garbage values when printed.
    for(int i=0;i<n;i++){
        if(xian[i].cou>maxl){
            maxl=xian[i].cou;
            start=xian[i];                
        }
    }


    printf("%d %d %d\n", maxl, start.x1, start.y1);

    return 0;
}