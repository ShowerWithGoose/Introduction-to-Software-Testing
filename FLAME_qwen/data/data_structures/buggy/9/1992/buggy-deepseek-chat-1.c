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
                A[i].x2=A[j].x1; // @@ This line incorrectly reassigns A[i].x2 to the same value (A[j].x1 equals A[i].x2), so it does not update to the next segment's endpoint. It should be A[i].x2 = A[j].x2.
                A[i].y2=A[j].y1; // @@ Similarly, this line incorrectly reassigns A[i].y2 to the same value (A[j].y1 equals A[i].y2), instead of updating to A[j].y2.
                j=i; // @@ This line sets j to i, but the inner loop will then increment j to i+1, skipping the current segment and potentially missing other connections. It should be j = -1 to restart from the beginning after updating.
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