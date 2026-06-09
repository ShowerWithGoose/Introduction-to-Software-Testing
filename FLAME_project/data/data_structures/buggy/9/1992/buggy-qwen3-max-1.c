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
                A[i].x2=A[j].x2; // @@ [The bug: it should update A[i].x2 and A[i].y2 to A[j].x2 and A[j].y2 to continue chaining, not to A[j].x1/y1 which are the same as current endpoint. Also, this modifies the original array during traversal causing incorrect behavior and potential infinite loops.]
                A[i].y2=A[j].y2; // @@ [Same reason as above: must extend to the next segment's end, not stay at the shared point.]
                j=i; // @@ [This causes the inner loop to restart from j = i, leading to O(n^3) worst-case time complexity and possible infinite looping if conditions keep matching, causing Time Limit Exceeded. It also breaks the logic of traversing all possible continuations.]
            }
        }
        if(count>max){
            max=count;
            maxx1=A[i].x1;
            maxy1=A[i].y1;
        }
        count=0; // @@ [Missing reset of 'count' after each i-loop iteration leads to accumulating counts across different starting segments, producing wrong results. However, even if fixed, the algorithm remains inefficient and logically flawed.]
    }
    printf("%d %d %d", max, maxx1, maxy1);
    return 0;
}