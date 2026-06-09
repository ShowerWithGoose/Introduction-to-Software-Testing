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
    for(int i=0;i<n;i++){ // @@ The algorithm is logically incorrect and inefficient (O(N^2) or worse with potential infinite loops). It fails to properly chain segments or track the start of the longest chain. The inner loop logic `j=i` combined with modifying `A[i]` coordinates creates undefined behavior and likely infinite loops or incorrect traversal, leading to Time Limit Exceeded or Wrong Answer. A correct approach requires sorting and dynamic programming or graph traversal.
        for(int j=0;j<n;j++){ // @@ This nested loop structure does not correctly identify continuous chains of segments. It checks all pairs repeatedly without maintaining state about the current chain length or sequence properly.
            if(A[i].x2==A[j].x1&&A[i].y2==A[j].y1){
                count++;
                A[i].x2=A[j].x1; // @@ Modifying the endpoint of the current segment `A[i]` to match the start of `A[j]` is redundant (they are already equal) and destroys the information about where the segment originally ended, breaking future connections if `A[i]` was part of a longer chain being built incorrectly.
                A[i].y2=A[j].y1; // @@ Same as above. This modification corrupts the data structure.
                j=i; // @@ Resetting `j` to `i` causes the inner loop to restart from `i+1` (due to `j++` in loop update) indefinitely if a connection is found, leading to an infinite loop or excessive iterations (Time Limit Exceeded). It also skips checking other potential connections properly.
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