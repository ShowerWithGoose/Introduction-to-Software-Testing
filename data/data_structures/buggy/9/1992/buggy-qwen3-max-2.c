#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#define MAX 100010
#define eps 1e-7
typedef long long ll;
struct line{
    int x1;
    int y1;
    int x2;
    int y2;
};
int main ()
{
    int n=0;
    scanf("%d", &n);
    struct line A[MAX];
    for(int i=0;i<n;i++){
        scanf("%d%d%d%d", &A[i].x1, &A[i].y1, &A[i].x2, &A[i].y2);
    }
    int count=0,max=0,maxx1=0,maxy1=0;
    for(int i=0;i<n;i++){
        count = 1; // @@ [The variable 'count' must be initialized to 1 for each new starting segment, not 0, because a single segment counts as length 1. Also, it should be reset inside the outer loop but before the inner loop.]
        int tx = A[i].x2, ty = A[i].y2; // @@ [Need to track current endpoint without modifying original array A, otherwise chaining breaks for other iterations.]
        for(int j=0;j<n;j++){
            if(A[i].x2==A[j].x1&&A[i].y2==A[j].y1){ // @@ [This condition uses modified A[i] if previous matches occurred, leading to incorrect comparisons. Should use tx, ty instead of A[i].x2, A[i].y2.]
                count++;
                A[i].x2=A[j].x1; // @@ [Modifying A[i] during traversal corrupts data for other iterations and breaks the logic since original segments are altered.]
                A[i].y2=A[j].y1; // @@ [Same issue: modifying input data leads to incorrect behavior in subsequent checks.]
                j=i; // @@ [Setting j=i causes the inner loop to restart from i, which may skip valid segments or cause infinite loops; also logically incorrect for chaining.]
            }
        }
        if(count>max){
            max=count;
            maxx1=A[i].x1;
            maxy1=A[i].y1;
        }
    }
    printf("%d %d %d", max, maxx1, maxy1);
    return 0;
}