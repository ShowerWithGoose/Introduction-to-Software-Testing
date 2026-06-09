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
    for(int i=0;i<n;i++){ // @@ The algorithm is logically incorrect and inefficient (O(N^2) or worse with potential infinite loops). It fails to properly chain segments to find the longest continuous line. The inner loop modifies loop variable 'j' to 'i', which can cause infinite loops or incorrect traversal, leading to Time Limit Exceeded or Wrong Answer. The logic does not track the length of connected components correctly.
        for(int j=0;j<n;j++){ // @@ Inner loop logic is flawed. It checks for a single connection but doesn't build a chain. Modifying 'j' inside the loop disrupts iteration.
            if(A[i].x2==A[j].x1&&A[i].y2==A[j].y1){
                count++;
                A[i].x2=A[j].x1; // @@ Modifying the endpoint of the current segment while iterating destroys the original data needed for further comparisons or other chains.
                A[i].y2=A[j].y1; // @@ Same as above.
                j=i; // @@ Resetting loop variable j to i causes the loop to restart or behave unpredictably, leading to excessive iterations (TLE) or logical errors.
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