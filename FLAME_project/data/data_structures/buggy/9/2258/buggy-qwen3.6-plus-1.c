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
    S xian[n];

    for (i = 0; i < n; i++) {
        scanf("%d %d %d %d", &xian[i].x1, &xian[i].y1, &xian[i].x2, &xian[i].y2);
        xian[i].cou = 1; // @@ The 'cou' field is not initialized to 1 in the original code, leading to undefined behavior when accumulating counts.
    }

    qsort(xian, n, sizeof(S), compare);
    for(int i=n-1;i>0;i--){
        for(int j=i-1;j>=0 && xian[j].x2>=xian[i].x1;j--){ // @@ The loop condition lacks a boundary check for j >= 0, which can cause out-of-bounds access. Also, the logic assumes sorting by x2 allows finding predecessors correctly, but the inner loop condition 'xian[j].x2>=xian[i].x1' might skip valid connections or access invalid memory if j goes negative.
            if(xian[i].x1==xian[j].x2&&xian[j].y2==xian[i].y1){
                xian[j].cou+=xian[i].cou;
                break;
            }
        }
    }
    int maxl = 1;
    S start ;
    start = xian[0]; // @@ The 'start' variable is uninitialized. If the first element is not the maximum, it might still hold garbage or incorrect data if not explicitly initialized before the loop.
    for(int i=0;i<n;i++){
        if(xian[i].cou>maxl){
            maxl=xian[i].cou;
            start=xian[i];                
        }
    }


    printf("%d %d %d\n", maxl, start.x1, start.y1);

    return 0;
}