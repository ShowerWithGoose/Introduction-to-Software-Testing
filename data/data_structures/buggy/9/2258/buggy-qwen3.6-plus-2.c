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
    S xian[n]; // @@ VLA elements are uninitialized, 'cou' contains garbage values.

    for (i = 0; i < n; i++)
        scanf("%d %d %d %d", &xian[i].x1, &xian[i].y1, &xian[i].x2, &xian[i].y2); // @@ Missing initialization of 'xian[i].cou = 1;' for each segment.

    qsort(xian, n, sizeof(S), compare);
    for(int i=n-1;i>0;i--){
        for(int j=i-1;xian[j].x2>=xian[i].x1;j--){ // @@ Missing 'j >= 0' boundary check, causing out-of-bounds array access.
            if(xian[i].x1==xian[j].x2&&xian[j].y2==xian[i].y1){
                xian[j].cou+=xian[i].cou; // @@ 'cou' is uninitialized, leading to undefined behavior and incorrect segment counts.
                break;
            }
        }
    }
    int maxl = 1;
    S start ; // @@ 'start' is uninitialized; if 'maxl' is never updated, it causes undefined behavior in printf.
    for(int i=0;i<n;i++){
        if(xian[i].cou>maxl){
            maxl=xian[i].cou;
            start=xian[i];                
        }
    }


    printf("%d %d %d\n", maxl, start.x1, start.y1);

    return 0;
}