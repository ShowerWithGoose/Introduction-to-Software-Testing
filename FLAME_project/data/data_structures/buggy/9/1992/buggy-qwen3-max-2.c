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
        for(int j=0;j<n;j++){
            if(A[i].x2==A[j].x1&&A[i].y2==A[j].y1){
                count++;
                A[i].x2=A[j].x2; // @@ [The original code incorrectly sets A[i].x2 = A[j].x1 (which equals A[i].x2), so it never extends the segment. It should update to A[j].x2 to continue chaining.]
                A[i].y2=A[j].y2; // @@ [Similarly, A[i].y2 should be updated to A[j].y2 to reflect the new endpoint after merging.]
                j=i; // @@ [This resets j to i, causing the inner loop to restart from j=i instead of continuing forward. This leads to infinite looping or incorrect traversal. It should break or mark used segments instead.]
            }
        }
        if(count>max){
            max=count;
            maxx1=A[i].x1;
            maxy1=A[i].y1;
        }
        count=0; // @@ [The count variable is not reset to 0 for each new starting segment i, leading to accumulation across different chains and incorrect results.]
    }
    printf("%d %d %d", max, maxx1, maxy1);
    return 0;
}