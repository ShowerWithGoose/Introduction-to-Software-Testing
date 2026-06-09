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
    for ( k = 0; k <n-j ; ++k) { // @@ Error: The condition uses variable j which is modified in the inner loop, causing the outer loop to execute only once (k=0). Additionally, the logic does not iterate over all possible starting segments.
        for ( j = 1; j <=n-k ; ++j) { // @@ Error: The upper bound `j <= n-k` allows j to become n-k, which results in accessing `lines[k+j]` out of bounds (since indices go up to n-1). Also, the inner loop modifies j, affecting the outer loop condition.
            if(lines[k].x2==lines[k+j].x1&&lines[k].y2==lines[k+j].y1){ // @@ Error: Potential out-of-bounds access due to inner loop bound. Also, the merging logic does not skip already used segments, leading to incorrect chain building.
                lines[k].num+=1; // @@ Error: Merging modifies the current segment while iterating, and does not mark the merged segment as used, causing double counting and incorrect chain detection.
                lines[k].x2=lines[k+j].x2;
                lines[k].y2=lines[k+j].y2;
            }
        }
    }
    int mid=lines[0].num;
    for (int i = 1; i < n-1; ++i) { // @@ Error: Loop ends at i < n-1, missing the last element (index n-1) when finding the maximum number of segments.
        mid=lines[i].num>mid?lines[i].num:mid;
    }
    for (int i = 0; i < n-1; ++i) { // @@ Error: Loop ends at i < n-1, missing the last element (index n-1) when searching for the starting point of the longest chain.
        if(lines[i].num==mid){
            printf("%d %d %d",lines[i].num,lines[i].x1,lines[i].y1);
            break;
        }
    }
    return 0;
}