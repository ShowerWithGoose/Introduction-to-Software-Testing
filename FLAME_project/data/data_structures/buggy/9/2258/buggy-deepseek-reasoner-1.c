#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x1, y1;
    int x2, y2;
    int cou; // @@ member not initialized for each segment, leads to garbage values
} S;

int compare(const void *a, const void *b) {
    S *sa = (S *)a;
    S *sb = (S *)b;
    return sa->x2 - sb->x2;
}

int main() {
    int n, i;
    scanf("%d", &n);
    S xian[n]; // @@ array members not initialized; cou contains indeterminate values

    for (i = 0; i < n; i++)
        scanf("%d %d %d %d", &xian[i].x1, &xian[i].y1, &xian[i].x2, &xian[i].y2); // missing initialization of xian[i].cou = 1

    qsort(xian, n, sizeof(S), compare);
    for(int i=n-1;i>0;i--){
        for(int j=i-1;xian[j].x2>=xian[i].x1;j--){ // @@ missing j>=0 condition; may cause out‑of‑bounds access when j becomes negative
            if(xian[i].x1==xian[j].x2&&xian[j].y2==xian[i].y1){
                xian[j].cou+=xian[i].cou; // @@ uses uninitialized cou values, leading to undefined behavior
                break;
            }
        }
    }
    int maxl = 1;
    S start ; // @@ not initialized; if no element has cou > 1, start remains uninitialized
    for(int i=0;i<n;i++){
        if(xian[i].cou>maxl){
            maxl=xian[i].cou;
            start=xian[i];                
        }
    }


    printf("%d %d %d\n", maxl, start.x1, start.y1);

    return 0;
}