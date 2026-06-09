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
    for ( k = 0; k <n-j ; ++k) { // @@ [The loop condition 'k < n - j' is incorrect because 'j' is modified inside the inner loop and reused across iterations, leading to unpredictable loop bounds. This causes some segments to be skipped or processed incorrectly.]
        for ( j = 1; j <=n-k ; ++j) { // @@ [The inner loop uses 'j' starting from 1 and goes up to 'n - k', but accesses 'lines[k + j]' which may go out of bounds when 'k + j == n'. Also, 'j' is declared outside the loop and reused, causing interference between outer loop iterations.]
            if(lines[k].x2==lines[k+j].x1&&lines[k].y2==lines[k+j].y1){
                lines[k].num+=1;
                lines[k].x2=lines[k+j].x2;
                lines[k].y2=lines[k+j].y2;
            }
        }
    }
    int mid=lines[0].num;
    for (int i = 1; i < n-1; ++i) { // @@ [This loop only checks up to index 'n-2', so it ignores the last element 'lines[n-1]'. If the longest chain ends at the last segment, it will be missed.]
        mid=lines[i].num>mid?lines[i].num:mid;
    }
    for (int i = 0; i < n-1; ++i) { // @@ [Same issue: this loop stops at 'n-2', so if the segment with maximum 'num' is at index 'n-1', it won't be printed. Additionally, the problem states there's only one maximum, but this may fail to find it due to incomplete search.]
        if(lines[i].num==mid){
            printf("%d %d %d",lines[i].num,lines[i].x1,lines[i].y1);
            break;
        }
    }
    return 0;
}