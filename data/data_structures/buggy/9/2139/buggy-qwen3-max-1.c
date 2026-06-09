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
    for ( k = 0; k <n-j ; ++k) { // @@ [Loop condition uses 'j' which is modified inside inner loop, causing unpredictable behavior and potential out-of-bounds access]
        for ( j = 1; j <=n-k ; ++j) { // @@ [Inner loop modifies 'j', which is also used in outer loop condition; this breaks loop control logic]
            if(lines[k].x2==lines[k+j].x1&&lines[k].y2==lines[k+j].y1){ // @@ [Accesses lines[k+j] which may exceed array bounds when k+j >= n]
                lines[k].num+=1;
                lines[k].x2=lines[k+j].x2;
                lines[k].y2=lines[k+j].y2;
            }
        }
    }
    int mid=lines[0].num;
    for (int i = 1; i < n-1; ++i) { // @@ [Loop stops at n-2, so last element lines[n-1] is never considered for maximum]
        mid=lines[i].num>mid?lines[i].num:mid;
    }
    for (int i = 0; i < n-1; ++i) { // @@ [Loop stops at n-2, so if the longest segment is at lines[n-1], it will be missed]
        if(lines[i].num==mid){
            printf("%d %d %d",lines[i].num,lines[i].x1,lines[i].y1);
            break;
        }
    }
    return 0;
}