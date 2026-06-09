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
    for ( k = 0; k <n-j ; ++k) { // @@ [The loop condition uses 'j' which is modified inside the inner loop, leading to unpredictable loop behavior and potential out-of-bounds access.]
        for ( j = 1; j <=n-k ; ++j) { // @@ [The inner loop modifies 'j', which is also used in the outer loop condition, causing incorrect iteration logic and possible buffer overflow when accessing lines[k+j].]
            if(lines[k].x2==lines[k+j].x1&&lines[k].y2==lines[k+j].y1){ // @@ [Accessing lines[k+j] may go out of bounds because j can be as large as n-k, making k+j == n, which is beyond valid index range [0, n-1].]
                lines[k].num+=1;
                lines[k].x2=lines[k+j].x2;
                lines[k].y2=lines[k+j].y2;
            }
        }
    }
    int mid=lines[0].num;
    for (int i = 1; i < n-1; ++i) { // @@ [Loop runs only up to n-2, so it ignores the last element lines[n-1], possibly missing the actual maximum.]
        mid=lines[i].num>mid?lines[i].num:mid;
    }
    for (int i = 0; i < n-1; ++i) { // @@ [Same issue: loop stops at n-2, so if the longest segment is at index n-1, it will not be printed.]
        if(lines[i].num==mid){
            printf("%d %d %d",lines[i].num,lines[i].x1,lines[i].y1);
            break;
        }
    }
    return 0;
}