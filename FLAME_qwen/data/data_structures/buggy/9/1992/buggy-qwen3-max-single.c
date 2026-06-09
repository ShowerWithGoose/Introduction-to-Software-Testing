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
                A[i].x2=A[j].x1; // @@ [This assignment breaks the chain traversal: it modifies A[i].x2 to A[j].x1 (which equals A[i].x2), effectively doing nothing useful, and prevents further extension beyond the immediate next segment. Also, it corrupts the original segment data needed for other chains.]
                A[i].y2=A[j].y1; // @@ [Same issue as above: overwrites endpoint with same value, and destroys original segment info. Should instead track current endpoint in temporary variables, not modify A[i].]
                j=i; // @@ [This resets inner loop index to i, causing incorrect loop behavior and potentially infinite loops or skipped segments. It does not correctly continue searching for the next connected segment after j.]
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