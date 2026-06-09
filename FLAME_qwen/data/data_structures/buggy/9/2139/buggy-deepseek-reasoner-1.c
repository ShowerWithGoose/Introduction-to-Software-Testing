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
    int n,k,j=0; // @@ [Variable j is used both as outer loop counter and inner loop counter, causing unintended modification of outer loop condition.]
    scanf("%d",&n);
    underline lines[n];
    for (int i = 0; i < n; ++i) {
        scanf(" %d %d %d %d",&lines[i].x1,&lines[i].y1,&lines[i].x2,&lines[i].y2);
        lines[i].num=1;
    }
    qsort(lines,n,sizeof(underline),cmp);
    for ( k = 0; k < n-j ; ++k) { // @@ [Condition depends on j, which is modified inside the inner loop, causing premature exit of outer loop.]
        for ( j = 1; j <= n-k ; ++j) { // @@ [Bound j <= n-k leads to index out-of-bounds because lines[k+j] accesses index n when j = n-k.]
            if(lines[k].x2==lines[k+j].x1&&lines[k].y2==lines[k+j].y1){ // @@ [Potential out-of-bounds access when j = n-k; also no marking of used segments leads to double counting.]
                lines[k].num+=1; // @@ [Incrementing num without removing used segments can cause overcounting when a segment is reused by different starting points.]
                lines[k].x2=lines[k+j].x2;
                lines[k].y2=lines[k+j].y2;
            }
        }
    }
    int mid=lines[0].num;
    for (int i = 1; i < n-1; ++i) { // @@ [Loop should start at i=0 and go to i<n to include all elements, otherwise index 0 and n-1 are missed.]
        mid=lines[i].num>mid?lines[i].num:mid;
    }
    for (int i = 0; i < n-1; ++i) {
        if(lines[i].num==mid){
            printf("%d %d %d",lines[i].num,lines[i].x1,lines[i].y1);
            break;
        }
    }
    return 0;
}