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
        count = 1; // @@ [The variable 'count' should be initialized to 1 for each new starting segment, not 0, because the current segment itself counts as one segment in the chain. Also, it must be reset inside the loop for each i.]
        int tx = A[i].x2, ty = A[i].y2; // @@ [Need to track the current endpoint dynamically without modifying the original array A, otherwise subsequent iterations get corrupted data.]
        for(int j=0;j<n;j++){
            if(A[i].x2==A[j].x1&&A[i].y2==A[j].y1){ // @@ [This condition uses the original A[i].x2/y2 which may have been modified in previous inner loop iterations (due to A[i].x2=A[j].x1 etc.), leading to incorrect comparisons. Also, the logic does not follow a proper chain traversal.]
                count++;
                A[i].x2=A[j].x1; // @@ [Modifying A[i] during traversal corrupts the original data and breaks future comparisons. This is a critical logical error.]
                A[i].y2=A[j].y1; // @@ [Same as above: modifying input data leads to undefined behavior in subsequent iterations.]
                j=i; // @@ [Setting j=i causes the inner loop to restart from index i, but this does not correctly simulate following a chain of connected segments. It also may cause infinite loops or skipped segments.]
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