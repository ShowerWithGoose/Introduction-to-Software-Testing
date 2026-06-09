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

    for (i = 0; i < n; i++)
        scanf("%d %d %d %d", &xian[i].x1, &xian[i].y1, &xian[i].x2, &xian[i].y2);

    qsort(xian, n, sizeof(S), compare);
    for(int i=n-1;i>0;i--){
        for(int j=i-1;xian[j].x2>=xian[i].x1;j--){ // @@ [The loop condition may access invalid memory when j becomes negative; also, 'cou' is uninitialized, leading to garbage values being used in accumulation]
            if(xian[i].x1==xian[j].x2&&xian[j].y2==xian[i].y1){
                xian[j].cou+=xian[i].cou; // @@ ['cou' was never initialized to 1, so adding garbage values leads to incorrect counts like 39878655]
                break;
            }
        }
    }
    int maxl = 1;
    S start ;
    for(int i=0;i<n;i++){
        if(xian[i].cou>maxl){ // @@ [Since 'cou' is uninitialized, this comparison uses garbage values, causing wrong maxl and wrong starting segment selection]
            maxl=xian[i].cou;
            start=xian[i];                
        }
    }


    printf("%d %d %d\n", maxl, start.x1, start.y1); // @@ [Because 'start' may be uninitialized if no 'cou' exceeds 1 (e.g., all segments are length 1 but 'cou' is garbage), output can be arbitrary]

    return 0;
}