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
    for ( k = 0; k <n-j ; ++k) { // @@ The loop condition `k < n - j` is incorrect because `j` is modified inside the inner loop and used as a dynamic bound for `k`, leading to premature termination or skipping of segments. It should likely be `k < n`.
        for ( j = 1; j <=n-k ; ++j) { // @@ The inner loop index `j` starts at 1 and accesses `lines[k+j]`. This logic attempts to chain segments, but it modifies `lines[k]` in place (`lines[k].x2`, `lines[k].y2`) while iterating. This greedy approach fails because it doesn't correctly track the longest chain starting from each segment independently, and modifying the current segment's end point affects subsequent comparisons incorrectly if multiple segments could potentially connect. More critically, the variable `j` is shared between the outer and inner loops in a way that corrupts the outer loop's state or logic due to the condition `k < n - j`.
            if(lines[k].x2==lines[k+j].x1&&lines[k].y2==lines[k+j].y1){
                lines[k].num+=1;
                lines[k].x2=lines[k+j].x2;
                lines[k].y2=lines[k+j].y2;
            }
        }
    }
    int mid=lines[0].num;
    for (int i = 1; i < n-1; ++i) { // @@ The loop bound `i < n - 1` skips the last element `lines[n-1]`. It should be `i < n` to check all segments for the maximum count.
        mid=lines[i].num>mid?lines[i].num:mid;
    }
    for (int i = 0; i < n-1; ++i) { // @@ The loop bound `i < n - 1` skips the last element `lines[n-1]`. It should be `i < n` to ensure the segment with the maximum count is found even if it's the last one.
        if(lines[i].num==mid){
            printf("%d %d %d",lines[i].num,lines[i].x1,lines[i].y1);
            break;
        }
    }
    return 0;
}