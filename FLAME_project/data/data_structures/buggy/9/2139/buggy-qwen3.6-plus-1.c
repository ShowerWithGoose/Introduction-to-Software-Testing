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
    for ( k = 0; k <n-j ; ++k) { // @@ The loop condition `k < n - j` is incorrect because `j` is modified inside the inner loop and used as a global state, leading to unpredictable loop bounds. It should likely be `k < n`.
        for ( j = 1; j <=n-k ; ++j) { // @@ The inner loop index `j` starts at 1 and accesses `lines[k+j]`, but `j` is also used in the outer loop condition. More importantly, this logic attempts to merge segments greedily but fails to handle chains correctly because it only looks ahead from the current `k` without updating `k` to the merged segment's end for further chaining in a single pass, or it incorrectly assumes sorted order allows simple adjacent merging which isn't true for arbitrary chains. Also, accessing `lines[k+j]` can go out of bounds if `k+j >= n`.
            if(lines[k].x2==lines[k+j].x1&&lines[k].y2==lines[k+j].y1){
                lines[k].num+=1;
                lines[k].x2=lines[k+j].x2;
                lines[k].y2=lines[k+j].y2;
            }
        }
    }
    int mid=lines[0].num;
    for (int i = 1; i < n-1; ++i) { // @@ The loop condition `i < n-1` skips the last element `lines[n-1]`, which might contain the maximum number of segments. It should be `i < n`.
        mid=lines[i].num>mid?lines[i].num:mid;
    }
    for (int i = 0; i < n-1; ++i) { // @@ Similarly, this loop skips the last element `lines[n-1]` when searching for the segment with the maximum count. It should be `i < n`.
        if(lines[i].num==mid){
            printf("%d %d %d",lines[i].num,lines[i].x1,lines[i].y1);
            break;
        }
    }
    return 0;
}