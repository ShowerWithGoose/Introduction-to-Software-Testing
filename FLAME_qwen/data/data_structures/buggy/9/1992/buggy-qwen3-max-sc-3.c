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
        count = 1; // @@ [The variable 'count' must be initialized to 1 for each new starting segment, not 0, because a single segment counts as length 1. Also, it should be reset inside the outer loop.]
        int tx = A[i].x2, ty = A[i].y2; // @@ [Need to track current endpoint without modifying original array; original code modifies A[i] which corrupts data for subsequent iterations.]
        for(int j=0;j<n;j++){
            if(A[i].x2==A[j].x1&&A[i].y2==A[j].y1){ // @@ [This condition uses original A[i].x2/y2 which may have been modified in previous inner loop iterations, leading to incorrect chaining. Should use tracked tx/ty instead.]
                count++;
                A[i].x2=A[j].x1; // @@ [Modifying A[i].x2 and A[i].y2 during traversal corrupts the original segment data, affecting other chains that might start from this segment or share endpoints.]
                A[i].y2=A[j].y1;
                j=i; // @@ [Setting j=i causes the inner loop to restart from index i, but this logic is flawed—it doesn't correctly continue searching for the next connected segment and may skip valid connections or loop infinitely in some cases.]
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