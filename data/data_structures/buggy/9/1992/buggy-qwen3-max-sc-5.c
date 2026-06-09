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
        count = 1; // @@ [The variable 'count' must be initialized to 1 for each new starting segment, not 0, because each segment itself counts as length 1. Also, it's not reset properly inside the loop.]
        int tx = A[i].x2, ty = A[i].y2; // @@ [Need to track current endpoint without modifying original array; original code modifies A[i] which corrupts data for future iterations.]
        for(int j=0;j<n;j++){
            if(A[i].x2==A[j].x1&&A[i].y2==A[j].y1){ // @@ [This condition uses modified A[i].x2/y2 from previous matches (due to assignment below), leading to incorrect chaining. Should use tx/ty instead.]
                count++;
                A[i].x2=A[j].x1; // @@ [Incorrectly modifies A[i].x2 to A[j].x1 (which equals A[i].x2), and should update to A[j].x2 to extend the chain. Also, modifying input array breaks other iterations.]
                A[i].y2=A[j].y1; // @@ [Same issue: sets to same value, should set to A[j].y2. Also corrupts original data.]
                j=i; // @@ [This resets inner loop index to i, causing unpredictable behavior and skipping segments. Should not manipulate loop variable like this.]
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