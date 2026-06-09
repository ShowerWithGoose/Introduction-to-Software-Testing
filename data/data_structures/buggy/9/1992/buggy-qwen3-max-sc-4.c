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
                A[i].x2=A[j].x1; // @@ [This assignment breaks the chain traversal logic. It should update to A[j].x2 and A[j].y2 to continue extending the segment, not revert to the start of the next segment.]
                A[i].y2=A[j].y1; // @@ [Same as above: this prevents correctly following the continuous line beyond the immediate next segment.]
                j=i; // @@ [This resets the inner loop index incorrectly. It causes the inner loop to restart from `i` instead of continuing to search for further connected segments, breaking the chain extension logic.]
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