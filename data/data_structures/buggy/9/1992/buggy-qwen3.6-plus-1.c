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
    int count=0,max=0,maxx1=0,maxy1=0; // @@ count is not reset for each starting segment i, and should be initialized to 1 for each chain.
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(A[i].x2==A[j].x1&&A[i].y2==A[j].y1){
                count++; // @@ count accumulates across different outer loop iterations instead of tracking the current chain length.
                A[i].x2=A[j].x1; // @@ Incorrectly updates the endpoint to the start point of the next segment; should be A[j].x2 to extend the chain.
                A[i].y2=A[j].y1; // @@ Incorrectly updates the endpoint to the start point of the next segment; should be A[j].y2 to extend the chain.
                j=i; // @@ Incorrectly resets the inner loop index; should be j=-1 to restart searching from the beginning for the next connected segment.
            }
        }
        if(count>max){ // @@ Compares the cumulative count across all i instead of the chain length for the current starting segment.
            max=count;
            maxx1=A[i].x1;
            maxy1=A[i].y1;
        }
    }
    printf("%d %d %d", max, maxx1, maxy1);
    return 0;
}