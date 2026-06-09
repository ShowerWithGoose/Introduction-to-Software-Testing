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
                A[i].x2=A[j].x1; // @@ [This line incorrectly reassigns A[i].x2 to the same value, and the subsequent assignment A[i].y2=A[j].y1 also does nothing useful. The logic for chaining segments is flawed; it should update A[i] to point to the next segment's endpoint, but the loop structure and j=i reset cause an infinite loop or incorrect counting.]
                A[i].y2=A[j].y1; // @@ [Same issue as above; this assignment is redundant and does not help in correctly linking segments.]
                j=i; // @@ [This line sets j back to i, causing the inner loop to restart from the same i, leading to an infinite loop when a match is found, as j will always be less than n and the condition will be rechecked indefinitely.]
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