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
    int count=0,max=0,maxx1=0,maxy1=0; // @@ count should be 1 and reset per start; also missing sorting of segments
    for(int i=0;i<n;i++){ // @@ algorithm requires segments sorted by x1 then y1; missing sort
        for(int j=0;j<n;j++){
            if(A[i].x2==A[j].x1&&A[i].y2==A[j].y1){
                count++; // @@ count not reset per i; should be initialized to 1 before inner loop
                A[i].x2=A[j].x1; // @@ should assign A[j].x2 (next endpoint); modifying A[i] corrupts data
                A[i].y2=A[j].y1; // @@ should assign A[j].y2; same issue
                j=i; // @@ flawed reset; should restart search from beginning but j=i leads to incorrect behavior
            }
        }
        if(count>max){ // @@ count may be cumulative from previous i; should be reset per i
            max=count;
            maxx1=A[i].x1;
            maxy1=A[i].y1;
        }
    }
    printf("%d %d %d", max, maxx1, maxy1);
    return 0;
}