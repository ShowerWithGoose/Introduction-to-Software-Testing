#include <stdio.h>
#include <stdlib.h>
typedef struct Line{
    int x1;
    int y1;
    int x2;
    int y2;
    int num;
}underline;
int cmp(const void *e1,const void *e2){
    return (((underline*)e1)->x1)-(((underline*)e2)->x1);
}
int main() {
    int n,k,j=0;
    scanf("%d",&n);
    underline lines[n];
    for (int i = 0; i < n; ++i) {
        scanf(" %d %d %d %d",&lines[i].x1,&lines[i].y1,&lines[i].x2,&lines[i].y2);
        lines[i].num=1;
    }
    qsort(lines,n,sizeof(underline),cmp);
    for ( k = 0; k <n-j ; ++k) { // @@ Misuse of variable j in loop condition; j is modified in the inner loop, causing unpredictable loop iterations and potential early termination.
        for ( j = 1; j <=n-k ; ++j) { // @@ Inner loop modifies j which is used in the outer loop condition, leading to incorrect loop control and undefined behavior.
            if(lines[k].x2==lines[k+j].x1&&lines[k].y2==lines[k+j].y1){
                lines[k].num+=1;
                lines[k].x2=lines[k+j].x2;
                lines[k].y2=lines[k+j].y2;
            }
        }
    }
    int mid=lines[0].num;
    for (int i = 1; i < n-1; ++i) { // @@ Loop condition should be i < n, otherwise the last element (index n-1) is not considered when finding the maximum.
        mid=lines[i].num>mid?lines[i].num:mid;
    }
    for (int i = 0; i < n-1; ++i) { // @@ Loop condition should be i < n, otherwise the last element is not checked when searching for the maximum value.
        if(lines[i].num==mid){
            printf("%d %d %d",lines[i].num,lines[i].x1,lines[i].y1);
            break;
        }
    }
    return 0;
}