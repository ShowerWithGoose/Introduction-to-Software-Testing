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
    for ( k = 0; k <n-j ; ++k) { // @@ The loop condition uses j which is initialized to 0 and never updated in a way that makes this loop work correctly; also the inner loop logic is flawed.
        for ( j = 1; j <=n-k ; ++j) { // @@ j is used as both the loop variable and the outer loop condition variable, causing undefined behavior; also j starts at 1 but should start at k+1 to compare with subsequent segments.
            if(lines[k].x2==lines[k+j].x1&&lines[k].y2==lines[k+j].y1){ // @@ k+j may exceed array bounds when j is large; also the logic incorrectly modifies lines[k] instead of properly chaining segments.
                lines[k].num+=1;
                lines[k].x2=lines[k+j].x2;
                lines[k].y2=lines[k+j].y2;
            }
        }
    }
    int mid=lines[0].num;
    for (int i = 1; i < n-1; ++i) { // @@ The loop should go up to i < n, not n-1, to check all elements.
        mid=lines[i].num>mid?lines[i].num:mid;
    }
    for (int i = 0; i < n-1; ++i) { // @@ Same issue: should be i < n to include the last element.
        if(lines[i].num==mid){
            printf("%d %d %d",lines[i].num,lines[i].x1,lines[i].y1);
            break;
        }
    }
    return 0;
}