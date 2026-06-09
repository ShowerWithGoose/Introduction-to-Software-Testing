#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
int flag[15];
int num=0,max=0,ans=0;
typedef struct {
    int x1,y1,x2,y2;
} Site;
Site line[15];
typedef struct NODE{
    int X1,Y1,X2,Y2;
    struct NODE *next;
} Node,*Npp;
Node *createNode(int m,int n){
    Node *tmp=(Node*) malloc(sizeof (Node));
    tmp->X1=m;
    tmp->Y1=n;
    tmp->next=NULL;
    return tmp;
}
int cmp(const void *a, const void *b) {
    Site x = *(Site *) a;
    Site y = *(Site *) b;
    if(x.x1>y.x1) return 1;
    return -1;} // @@ [The comparison function does not handle equality correctly; it should return 0 when x.x1 == y.x1, but more importantly, sorting only by x1 breaks the ability to chain segments that may start at same x1 but different y1, and also prevents backward chaining. However, the main issue is that the algorithm assumes segments are chained only in forward direction after sorting, but continuous lines can extend both forward and backward from a segment.]
void creatlist(int x,int n){
    int i=x,j=x+1;
    num=0;
    while(j<n){
        if(line[i].x2==line[j].x1 && line[i].y2==line[j].y1){
            flag[j]=1;
            i=j;
            num++;
        }
        j++;
    }
    if(num>max){
        max=num;
        ans=x;
    }
} // @@ [This function only checks for chains in the forward direction (increasing index after sorting), but a continuous line segment can also extend backward (i.e., find segments ending at the current segment's start). Thus, it misses longer chains that require backward extension. Also, it only considers immediate next segments in sorted order, not all possible connections.]
int main() {
    int n;
    scanf("%d",&n);
    for(int i =0;i<n;i++){
        scanf("%d%d%d%d",&line[i].x1,&line[i].y1,&line[i].x2,&line[i].y2);
    }
    qsort(line,n,sizeof(line[0]),cmp); // @@ [Sorting by x1 alone disrupts the natural connectivity of segments. Two segments that should connect might not be adjacent after sorting, especially if their x1 values are not in sequence. The algorithm then fails to find the full chain because it only scans forward linearly.]
    int k=0;
    while(k<n){
        if(flag[k]==0)
            creatlist(k,n);
        k++;
        } // @@ [The flag array is used to mark visited segments, but since creatlist only marks segments as visited when they are chained forward, segments that could be part of a longer chain starting from an earlier point might be skipped. Moreover, the algorithm never resets the flag array or explores all possible starting points thoroughly because it relies on sorted order and linear scan.]
    printf("%d %d %d",max+1,line[ans].x1,line[ans].y1);
    return 0;
}