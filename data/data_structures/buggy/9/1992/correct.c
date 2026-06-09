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
void sort(struct line p[],int n)
{
    int i,j;
    struct line tmp;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(p[i].x1<p[j].x1){
                tmp=p[i];
                p[i]=p[j];
                p[j]=tmp;
            }
        }
    }
}
int main ()
{
    int count=1,max=1,maxx1=0,maxy1=0;
    int n=0;
    scanf("%d", &n);
    struct line A[MAX];
    for(int i=0;i<n;i++){
        scanf("%d%d%d%d", &A[i].x1, &A[i].y1, &A[i].x2, &A[i].y2);
    }
    sort(A,n);
    for(int i=0;i<n;i++){
        int tempx2=A[i].x2;
        int tempy2=A[i].y2;
        for(int j=i;j<n;j++){
            if(tempx2==A[j].x1&&tempy2==A[j].y1){
                count++;
                tempx2=A[j].x2;
                tempy2=A[j].y2;
            }
        }
        if(count>max){
            max=count;
            maxx1=A[i].x1;
            maxy1=A[i].y1;
        }
        count=1;
    }
    printf("%d %d %d", max, maxx1, maxy1);
    return 0;
}
